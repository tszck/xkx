// Room: /d/lingxiao/wallw3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "城頭");
	set("long", @LONG
“大漠孤煙直，長河落日圓”。也只有在這種絕域寒地，方有此種
豪邁奇景現世。日薄西山，餘輝滿世，在這寂靜無聲的大漠之上，往往
有煙氣直升九霄，蔚為奇觀。視野盡處，一道橫貫大漠的長河，遮掩住
了紅火的落日。天色愈暗，直到那最後一道餘輝逝去，短短一柱香的時
間內，讓人的靈魂，也為之震撼。 
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"east" : __DIR__"wallw2",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -31030);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup(); 
	replace_program(ROOM);
}

