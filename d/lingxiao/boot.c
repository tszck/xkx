// Room: /d/lingxiao/boot.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG
這裏是一座大山的山麓，抬頭仰望，山上積雪皚皚，在日光下映得
閃爍生輝。山上雲海迷茫，雪峯林立，陽光交輝在白雲與飛雪之間，隱
隱能看見有一座城在山頂。路旁有一塊木板(sign)。
LONG ); 
	set("item_desc", ([
		"sign": HIG"萬古"+HIC"凌霄"+HIW"一羽毛"NOR+"\n"
	]) );
	set("exits",([
		"southeast"  : "/d/xuedao/sroad3",
		"westup"  : __DIR__"sroad1",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 2,
	]));
	set("outdoors", "lingxiao");
	set("coor/x", -31000);
	set("coor/y", -9000);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

