// Room: /d/nanshaolin/chanfang-2.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "禪房");
	set("long", @LONG
這裏是誦經的禪房。房中有一座小香爐，淡淡的清煙從中散出，彌
漫在整間房內。陽光透過窗格照在青石地上，在青煙中形成根根耀眼的
光柱。屋中的地上散放着幾個蒲團，幾個年青的僧人正閉目打坐於其上。
LONG
	);
	set("exits", ([
                "south" : __DIR__"chanfang-1",
	]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", 1790);
	set("coor/y", -6260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
