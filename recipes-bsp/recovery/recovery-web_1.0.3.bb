require recovery-web.inc

SRCREV = "5d68fcde19886c1fdf4987ec18ceaa346a40c68a"
SRCREV:dm520 = "f270af1e05411f06a97f3de82092a1c8e3398401"
SRCREV:dm820 = "${SRCREV:dm7080}"
SRCREV:dm900 = "33279a186e99b06037b677a0873c60167490a036"
SRCREV:dm920 = "${SRCREV:dm900}"
SRCREV:dm7080 = "e1a967cda27b0b02de1d945421b6111f7b6c96eb"
SRCREV:dreamone = "ffaa96d0e62568aa525728de98ffc10a07c3b8ec"
SRCREV:dreamtwo = "${SRCREV:dreamone}"

inherit opendreambox-git

BRANCH = "master"
BRANCH_dm520 = "dm520"
BRANCH_dm820 = "${BRANCH_dm7080}"
BRANCH_dm900 = "dm900"
BRANCH_dm920 = "${BRANCH_dm900}"
BRANCH_dm7080 = "dm7080"
BRANCH_dreamone = "dreamone"

COMPATIBLE_MACHINE = "^(dm520|dm820|dm900|dm920|dm7080|dreamone|dreamtwo)$"
