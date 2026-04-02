// Room: /d/nanshaolin/shanroad6.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
這是南少林後門外的一條小路，路旁長滿的青草。黃土鋪就的小路
看起來很齊整，似乎有人經常打掃。不遠處就是後山，山勢挺拔，景秀
境幽，峯上種滿了松樹，隨着微風拂過，傳來陣陣滔聲。前面西北方向
有一片很大的竹林，一條小徑直通林內。
LONG );
	set("exits", ([
		"northup"   : __DIR__"shanroad7",
		"southdown" : __DIR__"shanroad5",
                "northwest" : __DIR__"bamboo1",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6030);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}

