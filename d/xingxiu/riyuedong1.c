// Room: /d/xingxiu/riyuedong1.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;
void create()
{
	set("short", "日月洞口");
	set("long", @LONG
這裏是星宿海的盡頭。説是海，其實是片湖泊和沼澤，地形十分險
惡。方圓幾百裏都是一望無際的湖泊和沼澤，當地牧羊人就稱之為“海
”。這裏左右兩廂通向星宿海的深處，北邊是一座小石山，星宿派總舵
日月洞便設在這裏，洞口立着一個銅製牌子(paizi)。
LONG);
	set("exits", ([
		"north"     : __DIR__"riyuedong",
		"west"      : __DIR__"xxh4",
		"east"      : __DIR__"xxh3",
		"northwest" : __DIR__"xxhb2",
		"northeast" : __DIR__"xxhb1",
		"southdown" : __DIR__"huangdi",
	]));
	set("item_desc", ([
		"paizi" : "
	     星宿海福地
	     日月洞洞天。\n",
	]));
	set("objects", ([
		CLASS_D("xingxiu")+"/anran" : 1,
		CLASS_D("xingxiu")+"/first" : 1,
		__DIR__"npc/gushou" : 1,
		__DIR__"npc/haoshou" : 1,
		__DIR__"npc/boshou" : 1,
	]) );
	set("valid_startroom","1");
	set("coor/x", -50000);
	set("coor/y", 20300);
	set("coor/z", 100);
	set("outdoors", "xingxiu");
	setup();
	"/clone/board/xingxiu_b"->foo();
	replace_program(ROOM);
}

