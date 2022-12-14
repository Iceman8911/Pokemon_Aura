# Multi Start Menus
This branch allows you to fit as many options on the start menu as you wish after the flag FLAG_IS_MULTI_STARTMENU_ENABLED is set.
There are some important things you need to keep in mind though:

1. NUM_OF_START_MENUS creates as many menus as you need.
2. NUM_OF_START_MENU_OPTIONS is the max amount of options that can stay on one menu (it is not advised to go beyond 8).
3. FINAL_START_MENU_OPTION is the last option in the Menu actions ENUM you want to be printed out, e.g MENU_ACTION_PYRAMID_BAG.
4. IS_MULTI_STARTMENU_ENABLED is set by the flag FLAG_IS_MULTI_STARTMENU_ENABLED and is self explanatory. (IS_MULTI_STARTMENU_ENABLED seems pretty unnecessary, I'll probably get rid of it soon.)

Any necessary custom conditions can be added in BuildNormalStartMenu() in start_menu.c.
Remember, to activate the multi start menus, set the flag FLAG_IS_MULTI_STARTMENU_ENABLED.

## Caveat(s)
For now, NUM_OF_START_MENUS needs to be changed manually if the need arises although I intend to fix that soon, I'm burnt out lol. If you can't find the right number for it, just do FINAL_START_MENU_OPTION / NUM_OF_START_MENU_OPTIONS rounded up.



# Pokémon Emerald

This is a decompilation of Pokémon Emerald.

It builds the following ROM:

* [**pokeemerald.gba**](https://datomatic.no-intro.org/index.php?page=show_record&s=23&n=1961) `sha1: f3ae088181bf583e55daf962a92bb46f4f1d07b7`

To set up the repository, see [INSTALL.md](INSTALL.md).


## See also

Other disassembly and/or decompilation projects:
* [**Pokémon Red and Blue**](https://github.com/pret/pokered)
* [**Pokémon Gold and Silver (Space World '97 demo)**](https://github.com/pret/pokegold-spaceworld)
* [**Pokémon Yellow**](https://github.com/pret/pokeyellow)
* [**Pokémon Trading Card Game**](https://github.com/pret/poketcg)
* [**Pokémon Pinball**](https://github.com/pret/pokepinball)
* [**Pokémon Stadium**](https://github.com/pret/pokestadium)
* [**Pokémon Gold and Silver**](https://github.com/pret/pokegold)
* [**Pokémon Crystal**](https://github.com/pret/pokecrystal)
* [**Pokémon Ruby and Sapphire**](https://github.com/pret/pokeruby)
* [**Pokémon Pinball: Ruby & Sapphire**](https://github.com/pret/pokepinballrs)
* [**Pokémon FireRed and LeafGreen**](https://github.com/pret/pokefirered)
* [**Pokémon Mystery Dungeon: Red Rescue Team**](https://github.com/pret/pmd-red)


## Contacts

You can find us on [Discord](https://discord.gg/d5dubZ3) and [IRC](https://web.libera.chat/?#pret).
