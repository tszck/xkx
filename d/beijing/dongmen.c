// Room: /beijing/dongmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "東門");
	set("long", @LONG
這是東城門，城門正上方刻着“東門”兩個大字，城牆上貼着幾張
官府告示(gaoshi)。一條筆直的青石板大道向東西兩邊延伸。東邊是郊
外，越過城門可以看到驛道上人來車往，塵土飛揚。西邊通往城裏。西
北邊是朝陽門。
LONG );
	set("outdoors", "beijing");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east"  : __DIR__"road1",
		"west"  : __DIR__"dongcha2",
		"south" : __DIR__"matou",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -170);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return "輯拿天地會一眾反賊! \n舉報一人，賞金十兩;\n"
          "捉拿一人，賞金百兩。\n知情不報者，立斬!\n鰲拜發\n";
}
