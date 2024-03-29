SUMMARY = "Dreambox second stage bootloader"
SECTION = "base"
LICENSE = "CLOSED"
PROVIDES += "virtual/bootloader"
PRIORITY = "required"
DEPENDS = "dreambox-buildimage-native"

DATE = "${@time.strftime('%Y%m%d',time.gmtime())}"

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit deploy preserve_binary

do_configure[nostamp] = "1"

SRC_URI = "http://sources.dreamboxupdate.com/download/7020/secondstage-${MACHINE}-${PV}.bin"

PACKAGES = "${PN}"

S = "${WORKDIR}"

do_install() {
	install -d ${D}/tmp
	buildimage --arch ${MACHINE} --raw ${EXTRA_BUILDCMD} \
	--erase-block-size ${DREAMBOX_ERASE_BLOCK_SIZE} \
	--flash-size ${DREAMBOX_FLASH_SIZE} \
	--sector-size ${DREAMBOX_SECTOR_SIZE} \
	--boot-partition=${DREAMBOX_PART0_SIZE}:secondstage-${MACHINE}-${PV}.bin \
	> ${D}/tmp/secondstage-${MACHINE}.bin
}

# busybox nandwrite requires oob patch and is not working in every box
RDEPENDS:${PN} = "mtd-utils"
FILES:${PN} = "/tmp/secondstage-${MACHINE}.bin"

pkg_postinst:${PN}() {
	if [ -z "$D" ] && grep -q '\<${MACHINE}\>' /proc/stb/info/model; then
		if [ -f /tmp/secondstage-${MACHINE}.bin ]; then
			flash_erase /dev/mtd1 0 0 2>/dev/null
			nandwrite -m -n -o /dev/mtd1 /tmp/secondstage-${MACHINE}.bin 2>/dev/null
			rm -f /tmp/secondstage-${MACHINE}.bin
		fi
	fi
}

do_deploy() {
	install -d ${DEPLOYDIR}
	install -m 0644 secondstage-${MACHINE}-${PV}.bin ${DEPLOYDIR}/secondstage-${MACHINE}.bin
}

addtask deploy before do_package after do_install
