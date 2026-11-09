# microdox-qmk

My QMK keymap for the [Boardsource Microdox](https://boardsource.xyz) v1
(Pro Micro, RGB underglow, one rotary encoder per half).

It is cloned inside my
[qmk-userspace](https://github.com/ned-si/qmk-userspace) checkout, at
`keyboards/boardsource/microdox/keymaps/nedsi` (git-ignored there). The shared
code (layer enum, row macros, custom keycodes, tap dances) lives in
qmk-userspace, in `users/nedsi`.

## Target

`boardsource/microdox/v1`. Its matrix, split serial pin (D2) and underglow
(12 LEDs on D3) match upstream. The encoder is not part of the upstream v1
definition, so `config.h` adds it (A on D5, B on B7); it turns the volume.

To fit the 28 KB of the Pro Micro, `rules.mk` turns off mouse keys (unused)
and Bootmagic.

## Build and flash

From a machine set up as described in the qmk-userspace README:

```sh
qmk compile -kb boardsource/microdox/v1 -km nedsi
qmk flash   -kb boardsource/microdox/v1 -km nedsi
```

Flash each half: plug it in, run `qmk flash`, then double-tap its reset
button (Caterina bootloader). Handedness is stored in EEPROM (`EE_HANDS`): on a
fresh controller, flash with `-bl avrdude-split-left` / `avrdude-split-right`
once.
