// tynroad.c 桃園小路
// by Marz 

inherit ROOM;

string* npcs = ({
	"little_monkey",
	"monkey",
	"little_monkey",
	"little_bee",
	"bee",
	"little_bee",
});
void create()
{
	int i = random(sizeof(npcs));
	    
	set("short", "桃園小路");
	set("long", @LONG
眼前豁然開朗，你輕鬆地走在桃園邊的小路上。路上落英繽紛，一
邊是桃樹林，盛開着粉紅的桃花，紅雲一片，望不到邊。還可以看見蜜
蜂「嗡嗡」地在花間飛上飛下忙個不停，間或傳來猿猴的嘰咋聲。這兒
是武當山腳，北邊是條環山的黃土路。
LONG );
	set("outdoors", "wudang");
	set("exits", ([
		"south" : __DIR__"tyroad8",
	]));
	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1
	]));
//	set("no_clean_up", 0);
	set("coor/x", -1990);
	set("coor/y", -920);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
