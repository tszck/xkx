// Room: /beijing/yongdingmen.c


inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "永定門");
	set("long", @LONG
這裏是永定門，城門正上方刻着“永定門”三個大字，城牆上貼着
幾張官府告示 (gaoshi)。每天都有許多人從這裏是出入京城，正因如此
官兵盤查得格外仔細。 一條筆直的大道向南北兩邊延伸。南邊的驛道上
人來車往，塵土飛揚。北邊通往城中心。
LONG );
        set("outdoors", "beijing");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"south" : __DIR__"road5",
		"north" : __DIR__"nandaj2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -200);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return "輯拿天地會一衆反賊! \n舉報一人，賞金十兩;\n"
          "捉拿一人，賞金百兩。\n知情不報者，立斬!\n鰲拜發\n";
}
