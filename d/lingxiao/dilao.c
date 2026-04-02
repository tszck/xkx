// Room: /d/lingxiao/dilao.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "地牢");
	set("long", @LONG
這間地牢在監獄的最下面，但卻有淡淡的陽光透入。地牢中間，一
個身影手持鐵鏈，傲然站在石柱旁。日光透將進來，只見那人滿臉花白
鬍子，身材魁梧，背脊微弓，倒似這間小小石室裝不下他這個大身子似
的，眼光耀如閃電，威猛無儔。 
LONG );
	set("exits", ([
		"out" : __DIR__"didi",
	]));
	set("objects", ([ 
		CLASS_D("lingxiao")+"/bai" : 1,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8910);
	set("coor/z", 120);
	setup(); 
	replace_program(ROOM);
}

