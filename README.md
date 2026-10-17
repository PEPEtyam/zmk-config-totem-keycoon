# zmk-config-totem-keycoon

ZMK firmware config for the [TOTEM](https://github.com/GEIGEIGEIST/TOTEM) split keyboard (38 keys, wireless). Home-row mods, five layers, thumb-driven layer switching, ZMK Studio enabled. Firmware is built by GitHub Actions on every push.

```
config/totem.keymap   layers, combos, behaviors
config/totem.conf     ZMK Studio + settings storage
config/west.yml       ZMK upstream manifest
build.yaml            build matrix
```

## Layers

Legend: `⇧ ⌃ ⌥ ⌘` hold-tap on hold, `·` transparent (falls through to BASE).

### BASE

```
 Q    W    E    R    T  │  Y    U    I    O    P
 A⇧   S⌃   D⌥   F⌘   G  │  H    J⌘   K⌥   L⌃   ;⇧
 Esc  Z    X    C    V   B  │  N    M    ,    .    /    Enter
              Tab  SYM  Space │ Bksp NUM  FN
```

Home-row mods: `balanced` flavor, 280 ms tapping term, 175 ms quick-tap, 150 ms prior-idle.

### NUM — hold right middle thumb

```
 1    2    3    4    5  │  6    7    8    9    0
 ⇧    ⌃    ⌥    ⌘    ~  │  ←    ↓    ↑    →    Caps
 Esc  !    @    #    $   %  │  Home PgDn PgUp End  PrtSc Enter
```

### SYM — hold left middle thumb

```
 !    @    #    $    %  │  6    7    8    9    0
 `    |    <    >    \  │  \    <    |    >    "
 Esc  ~    {    }    [   ]  │  ^    &    *    (    )    Enter
```

### ADJUST — hold both middle thumbs (NUM + SYM)

Every key sends `Ctrl+Option+Cmd+key` (hyper without Shift), used by [skhd](https://github.com/koekeishiya/skhd) hotkeys. `H J K L` send arrows for window management.

```
 Q    W    E    R    T  │  Y    U    I    O    P
 A    S    D    F    G  │  ←    ↓    ↑    →    ;
 ·    Z    X    C    V   B  │  N    M    ,    .    /    ·
```

skhd bindings (`~/.skhdrc`): `B` Arc, `G` Ghostty, `Z` Telegram, `V` DBeaver.

### FN — hold right outer thumb

```
 F1   F2   F3   F4   F5 │  ·    Bri- Bri+ ·    ·
 F6   F7   F8   F9   F10│  ·    Vol- Mute Vol+ ·
 BtClr BT0 BT1  BT2  F11  F12 │ ·  Prev Play Next ·   BtClrAll
```

`BtClr` clears the selected Bluetooth profile, `BtClrAll` clears all of them; `BT0–2` select profiles.

## Combos

Press both keys at once (45 ms window, 125 ms prior-idle). All except the thumb ones work on BASE only.

| Combo | Output | | Combo | Output |
|---|---|---|---|---|
| `Q+W` | `` ` `` | | `R+T` | `[` |
| `W+E` | `_` | | `Y+U` | `]` |
| `E+R` | `-` | | `F+G` | `(` |
| `R+G` | `+` | | `H+J` | `)` |
| `U+H` | `=` | | `V+B` | `{` |
| `U+I` | `:` | | `N+M` | `}` |
| `I+O` | `;` | | `O+P` | `'` |

Thumb combos (all layers):

| Combo | Output |
|---|---|
| `Space+Bksp` | `Cmd+Space` (switch input language, 35 ms) |
| `Tab+SYM+Space` | `'` |
| `Bksp+NUM+FN` | `"` |

## Build and flash

Push to GitHub, open the *Actions* tab, download the firmware artifact, and flash each half in bootloader mode (the board has dedicated reset and bootloader keys). Keymap can also be edited live in [ZMK Studio](https://zmk.studio).
