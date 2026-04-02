// Room: /d/nanshaolin/twdian.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIR"天王殿"NOR);
	set("long", @LONG
這裏是少林寺的中殿天王殿。殿內香菸燎繞，幔角叮咚。香火比前
殿要旺盛的多。正前方供着個大肚子，似乎永遠都笑咪咪的彌勒佛。四
大天王分列兩旁，分執“風調雨順”。兩側香桌上擺滿了四季果蔬，彌
勒的身後站立的是韋馱。只見他金盔金甲，年輕英俊，威風凜凜，雙手
合十，金剛杵橫放腕上。
LONG );

	set("exits", ([
		"south" : __DIR__"qdian",
		"north" : __DIR__"sblu-1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangxian" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));

	set("coor/x", 1820);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

