//ROOM: /d/yanziwu/shuiyun.c

inherit ROOM;

void create()
{
	set("short", "水雲軒");
	set("long",@LONG
湖心的一座小小的亭臺，四面環水，只有西側有一條曲橋與岸上相
連。軒中清風拂面，水波微揚，一羣羣遊魚清晰可見，別有一番詩情畫
意。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"west" : __DIR__"jiashan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 850);
	set("coor/y", -1540);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}