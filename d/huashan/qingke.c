// qingke.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "青柯坪");
	set("long", @LONG
走過崎嶇的十八盤，穿過雲門，就到了青柯坪。青柯坪是一山間盆
地，地勢略為平坦。從這裏開始，上山的路都是由原地鑿出的石階。遠
遠望見一個小小石亭，便是賭棋亭了。相傳宋太祖與華夷先生曾弈棋於
此，將華山作為賭注，宋太祖輸了，從此華山上的土地就不須繳納錢糧。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"eastup"    : __DIR__"huixinshi",
		"northdown" : __DIR__"yunmen",
	]));
	set("objects",([ 
		__DIR__"npc/tao-jun" : 1,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -910);
	set("coor/y", 240);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
 
