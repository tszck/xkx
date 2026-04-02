// Room: /d/nanshaolin/shanroad3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
這是南少林後門外的一條小路，路旁長滿的青草。黃土鋪就的小路
看起來很齊整，似乎有人經常打掃。前方少林後山，山勢挺拔，景秀境
幽，峯上種滿了松樹，隨着微風拂過，傳來陣陣滔聲。
LONG );
	set("exits", ([
		"north"     : __DIR__"shanroad4",
		"southdown" : __DIR__"shanroad2",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6060);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}

