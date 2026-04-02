// Room: /d/taohua/neishi1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "落英廊");
	set("long", @LONG
這是一間竹編的通道小間，連接着飯廳和臥室。壁上掛着幾張山水
潑墨，手筆極是遒勁，顯見出自名家之手。室內很隨意地擺着一些小竹
椅，當中圍着一張小竹几，几上一壺茶水正香，水氣嫋嫋。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"woshi1",
		"west"  : __DIR__"fanting",
		"south" : __DIR__"zoulang2",
		"north" : __DIR__"neishi2",
	]));
	set("outdoors","taohua");
	set("objects", ([
		__DIR__"npc/yapu" : 1,
	]));

	set("coor/x", 9000);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}