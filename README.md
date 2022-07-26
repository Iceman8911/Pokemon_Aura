## Dynamic Multichoices

This is a feature branch that makes script multichoices (pory and standard!) much more sane to use and edit. Never have to add a whole multichoice menu to 4 different files again!

It's pretty simple to use.

First step is to  
`bufferdynamicmulti string1, string2, string3, . . .  `  
(up to 6 strings can be specified. Missing strings will be filled automatically.)
then  
`multichoice Xloc Yloc, MULTI_DYNAMIC_Z, ignoreB`  
 where Z is the number of choices you want your menu to have.
Other than this, it works exactly like the standard multichoice. This allows you to generate multichoices in your script rather than having to define new constants in other files for them.
Example Porycript:
```
text MNM_1 {
    "Sweet"
}

text MNM_2 {
    "Spicy"
}

text MNM_3 {
    "Sour"
}

script myNewMultiScript {
    msgbox("What's your favorite flavor?")
    bufferdynamicmulti(MNM_1, MNM_2, MNM_3)
    multichoice(0, 0, MULTI_DYNAMIC_3, 1)
    switch (var(VAR_RESULT)) {
        case 0:
            msgbox("You chose Sweet!)
            goto(sweetScriptActions)
        case 1:
            msgbox("You chose Spicy!)
            goto(sweetScriptActions)
        case 2:
            msgbox("You chose Sour!)
            goto(sweetScriptActions)
    }
    release
    end
}
```
And this is all you need! No more tracking multiple files for basic multichoices!

# NOTICE FOR MERGING!
### BEFORE merging this, to save yourself a headache, replace EVERY INSTANCE of "gStringVar4" with "gSystemString"
### There should be NEAR 800 INSTANCES.

==ORIGINAL README BELOW==

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
