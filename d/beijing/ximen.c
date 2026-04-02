// Room: /beijing/ximen.c

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "西門");
	set("long", @LONG
這是西城門，幾年前曾經遭到土匪的攻打，因此顯得有些破敗。城
門正上方勉勉強強可以認出“西門”兩個大字，城牆上貼着幾張通緝告
示(gaoshi)。罪犯常常從這裏逃出京城，官兵們戒備森嚴，動不動就截
住行人盤問。一條筆直的青石板大道向東西兩邊延伸。西邊是郊外，騎
馬的、坐轎的、走路的，行人匆匆。東邊是城裏。
LONG );
        set("outdoors", "beijing");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : __DIR__"xichang2",
		"west" : __DIR__"ximenwai",
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
	set("coor/x", -230);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return "輯拿天地會一衆反賊! \n舉報一人，賞金十兩;\n"
          "捉拿一人，賞金百兩。\n知情不報者，立斬!\n鰲拜發\n";
}
