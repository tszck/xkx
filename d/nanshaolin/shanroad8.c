// Room: /d/nanshaolin/shanroad8.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
這是南少林後門外的一條小路，路旁長滿的青草。黃土鋪就的小路
看起來很齊整，似乎有人經常打掃。前面就是後山，山勢挺拔，景秀境
幽，峯上種滿了松樹，隨着微風拂過，傳來陣陣滔聲。東面是一片松林，
林外豎着一塊木牌(mupai)。
LONG );
	set("exits", ([
		"east"      : __DIR__"shulin1",
		"southwest" : __DIR__"shanroad7",
        ]));
        set("item_desc",([
		"mupai"	:   "少林寺護法松林，違令擅入者殺無赦！\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1830);
	set("coor/y", -6010);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}

