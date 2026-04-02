// /d/meizhuang/neiyuan.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "內院");
	set("long", @LONG
這裏是梅莊的內院，從這裏走過去就可以找到四位莊主，這裏似乎
非常安靜，可以聽見落葉觸地的聲音，但又似乎非常吵鬧，經常可以聽
到嘈雜的琴聲，但這琴聲又可以將你的心絃打亂，你真不知道該怎麼形
容這個地方。有一位壯年的漢子，腰懸寶劍守在院門口。
LONG
	);
	set("outdoors", "meizhuang");
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"senlin1",
		"north" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/huyuan" : 1,
		"/d/shaolin/npc/mu-ren" : 5,
	]));

	set("coor/x", 3500);
	set("coor/y", -1390);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

