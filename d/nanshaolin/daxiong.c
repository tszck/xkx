// Room: /d/nanshaolin/daxiong.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"大雄寶殿"NOR);
	set("long", @LONG
這裏是少林寺的大雄寶殿。面闊五間，進深四間。正中供奉着如來
三寶，左右各是文殊、普賢諸位菩薩。一羣僧侶正自焚香誦經，仰觀我
佛拈花微笑的神態，令人頓感肅然起敬。這裏殿堂寬大，亦是方丈大師
召集闔寺羣僧議事之所。
LONG );
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"pingtai",
		"north" : __DIR__"stoneroad1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



