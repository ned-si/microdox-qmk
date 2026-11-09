ENCODER_ENABLE = yes
TAP_DANCE_ENABLE = yes
NKRO_ENABLE = yes
LTO_ENABLE = yes
EXTRAKEY_ENABLE = yes

# Mouse keys: no mouse keycodes in this keymap or the userspace, and the
# firmware does not fit the Pro Micro's 28 KB with them.
MOUSEKEY_ENABLE = no
# Off, as on the 2021 firmware.
BOOTMAGIC_ENABLE = no
# OLED stays on (upstream default, unlike the 2021 firmware): upstream
# microdox.c only compiles its encoder code when OLED is enabled.
