// Room: /d/city/dongmen.c
// Last Modified by winder on July. 20 2000

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "廣儲門");
	set("long", @LONG
這是東城門，城門正上方刻着“廣儲門”三個楷書大字，城牆上貼
着幾張官府告示(gaoshi)。官兵們警惕地注視着過往行人，你最好小心
爲妙。一條筆直的青石板大道向東西兩邊延伸。東邊是郊外，隱約可見
一片一望無際的樹林，神祕莫測。北面有一片茂盛的青竹林。南面是一
大片的草地，西邊是城裏。
LONG );
	set("outdoors", "yangzhoue");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east"  : "/d/taishan/yidao",
		"west"  : __DIR__"dashidongjie",
		"north" : __DIR__"ml1",
		"south" : __DIR__"jiaowai1",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));

	set("coor/x", 70);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n揚州知府\n程藥發\n";
}