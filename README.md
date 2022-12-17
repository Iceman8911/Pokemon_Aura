# Coloured Battle Text Effectiveness

This is the implemented version of a somewhat outdated pokecommunity post about [**Coloured Type Effectiveness In-Battle Text**](https://www.pokecommunity.com/showpost.php?p=10167016&postcount=83). It shows a different colored text of the element of a move in-battle (By Default: Super Effective - Green, Not Very Effective - Red, Not Effective at all - Faded Gray). It also supports Inverse and Double/Multi Battles.

The colours of the text can be edited in "src/battle_message.c". Just search for the line with the comment "//For coloured battle text" in the struct "gTextOnWindowsInfo_Normal" .


## Added by me
1. STAB move compatibility has been implemented.
2. There are now 2 ways to display text (albeit one looks much cleaner in my opinion).


## Important Stuff to Note
1. If defined, VIBRANT_STAB_TYPE_EFFECTIVENESS displays a more vibrant and bolder color scheme. Else the difference in display between STAB and non-STAB moves is just the font.
2. If defined, ONLY_ELEMENT_TEXT_COLOR_CHANGE makes just the move's typing gets its colour changed. Else the entire "TYPE/(insert_element)" gets its colour changed.

Both of these defines can be found in "gflib\text.h". If you don't like any, comment them out. At the moment, VIBRANT_STAB_TYPE_EFFECTIVENESS is the only one commented out since it still looks somewhat "raw".


## To do
1. Moves like Counter, Mirror Coat, Metal Burst, Seismic Toss, Night Shade, etc can show as super effective, not very effective,etc. I'll fix this later.



# Pokémon Emerald

## What is the pokeemerald Expansion?

The Pokeemerald Expansion is a collection of feature branches that can be integrated into existing [pokeemerald](https://github.com/pret/pokeemerald) projects.

## What features are included?
- Upgraded battle engine.
    - Fairy Type.
    - Physical/Special/Status Category Split.
    - New moves and abilities up to SwSh.
    - Options to change behaviors and data by generation.
    - Mega Evolution and Primal Reversion
    - Z-Moves
- Pokémon Species from newer Generations (with the option to disable them if needed).
    - Updates Hoenn's Regional Dex to match ORAS'.
    - Updates National Dex incorporating all the new species.
    - Option to change base stats by generation.
    - New evolution methods.
    - Hidden Abilities data (How to make them available is up to the user).
- Items from newer Generations and updated item effects for battle and field use.

Certain mechanics, moves, abilities and species sprites are missing. For more information, see [the project's milestones](https://github.com/rh-hideout/pokeemerald-expansion/milestones).

### [Documentation on features can be found here](https://github.com/rh-hideout/pokeemerald-expansion/wiki)

## Who maintains the project?

The project was originally started by DizzyEgg alongside other contributors.

The project has now gotten larger and DizzyEgg is now maintaining the project as part of the ROM Hacking Hideout community. Some members of this community are taking on larger roles to help maintain the project.

### Please consider crediting the entire [list of contributors](https://github.com/rh-hideout/pokeemerald-expansion/wiki/Credits) in your project, as they have all worked hard to develop this project :)

## Can I contribute even if I'm not a member of ROM Hacking Hideout?

Yes! Contributions are welcome via Pull Requests and they will be reviewed by maintainers. Don't feel discouraged if we take a bit to review your PR, we'll get to it.

## What is ROM Hacking Hideout?

A Discord-based ROM hacking community that has many members who hack using the disassembly and decompilation projects for Pokémon. Quite a few contributors to the original feature branches by DizzyEgg were members of ROM Hacking Hideout. You can call it RHH for short!

[Click here to join the RHH Discord Server!](https://discord.gg/6CzjAG6GZk)
