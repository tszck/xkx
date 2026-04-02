// Room: /d/lingxiao/sroad1.c
// Last Modified by winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG
從這裏開始，就是上凌宵城的山路了。抬頭一望，雪峯高插雲霄，
看不見頂，自己站立之處，僅僅是在山腳高一點，卻已有點“高處不勝
寒”之感了。一路行來，雖還在山腳，卻已感覺到寒氣逼人，路旁的樹
上，全掛滿了白雪冰凌，一陣冷風吹來，已讓人縮頭籠手。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"eastdown"  : __DIR__"boot",
		"northup"   : __DIR__"sroad2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -9000);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

