// Room: /d/village/alley1.c

inherit ROOM;

void create()
{
        set("short", "小巷");
        set("long", @LONG
這是一條黑暗、骯髒的小巷，空氣中彷彿飄揚着一股罪惡的氣息，西
北邊通向小巷深處，正人君子是不會往那邊走去的。往東走就會回到村中
大路了。
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"sroad3",
            "northwest" : __DIR__"alley2",
	]));
        set("no_clean_up", 0);
        set("outdoors", "village");

	set("coor/x", -980);
	set("coor/y", 250);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}