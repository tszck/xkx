// /d/meizhuang/xiaolu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "蜿蜒小徑");
	set("long", @LONG
這條小路的兩旁種着無數的梅花，雖然還沒到梅花盛開的季節，但
透過這密密的梅林，你似乎已經聞到了陣陣的梅花的幽香，這時你已經
發現你快走到莊園的門口，你暗地裏加快了腳步．
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"shijie",
		"north" : __DIR__"gate",
	]));
	set("outdoors", "meizhuang");
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1450);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
