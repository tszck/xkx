//TORJQ3.C

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
大路已經延伸到了盡頭，西首方向一座門樓高聳，門前有十幾個金
衣人往返巡邏，氣勢森嚴。門樓兩旁並插鑲金青龍旗，迎風招展，烈烈
生威。紅色大門緊閉，不時有教眾從側小門進出，也被盤查得緊。向西
北而行，是去洪水旗的路，而西南方向則通往烈火旗。
LONG );
	set("exits", ([
		"east" :      __DIR__"jmqmen",
		"southeast" : __DIR__"tojmq2",
		"northeast" : __DIR__"tohtq1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52060);
	set("coor/y", 860);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}