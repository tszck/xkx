// tyroad11.c 桃園小路
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
眼前豁然開朗，你輕鬆地走在桃園邊的小路上。兩邊是桃樹林，樹
上盛開着粉紅的桃花，紅雲一片，望不到邊。不時有蜜蜂「嗡嗡」地飛
過，消失在在花叢中；幾隻猴子在樹上互相追逐着，嘰嘰喳喳地爭搶桃
子。
LONG );
	set("outdoors", "wudang");
	set("exits", ([
		"west" : __DIR__"tyroad10",
		"east" : __DIR__"tyroad12",
	]));
	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1
	]));
//	set("no_clean_up", 0);
	set("coor/x", -1960);
	set("coor/y", -930);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
