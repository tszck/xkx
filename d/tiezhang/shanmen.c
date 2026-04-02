// Room: /d/tiezhang/shanmen.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "山門");
	set("long", @LONG
這裏就是江湖上聞風喪膽的“鐵掌幫”。自從“鐵掌殲衡山”一役
將衡山派打得一蹶不振之後，幫主鐵掌水上漂的名頭威震江湖。這裏是
進山的必經之路，曲的小路通向山裏。路的一側立着一塊牌子(paizi) 。
兩旁的樹林內不時傳出一些響聲，似乎有人在暗中監視。
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 2 */
		"northup"   : __DIR__"shanlu1",
		"southdown" : __DIR__"shanjiao",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/heiyi" : 2,
		CLASS_D("tiezhang")+"/first" : 1,
	]));
	set("item_desc", ([ /* sizeof() == 1 */
		"paizi" : "[31m“擅入者--死”[0;37;0m\n",
	]));
	set("no_clean_up", 0);

	set("coor/x", -2040);
	set("coor/y", -2000);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "鐵掌幫") &&
		dir == "northup" && (int)me->query("combat_exp", 1) >= 10000 &&
		objectp(present("heiyi bangzhong", environment(me))))
		return notify_fail("黑衣幫眾抽刀攔住你的去路，説道：“你不是鐵掌幫弟子，不能上山！\n");

	return ::valid_leave(me, dir);
}
