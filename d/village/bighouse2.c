// Room: /d/village/bighouse2.c

inherit ROOM;

void create()
{
        set("short", "內室");
	set("long", @LONG
這裏是一間寢室，屋子中間有一張大牀，牀上的被褥居然是綢緞的，
看來這個土財主對自己並不是十分刻薄。屋裏擺着幾隻木箱子，牆角里有
一隻大櫃子(cabinet)。
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"bighouse1",
        ]));
        set("no_clean_up", 0);

	set("coor/x", -950);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
 