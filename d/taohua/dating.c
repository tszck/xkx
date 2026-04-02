// Room: /d/taohua/hall.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

string look_bagua();

void create()
{
	set("short", "方廳");
	set("long", @LONG
這是一間非常寬敞的方廳。牆上掛着許多的名人字畫，個個都是海
內罕見的精品。而在門楣之上釘着八片鐵片， 排作八卦(bagua)圖案，
卻又不似尋常的八卦那麼排的整齊，疏疏落落，歪斜不稱，顯然與四周
的佈置極不協調。南面隔着荷塘是一片竹林。
LONG
	);
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"zoulang4",
		"west"  : __DIR__"zoulang1",
		"south" : __DIR__"hetang",
		"north" : __DIR__"jingshe",
	]));
	set("item_desc", ([
		"bagua" : (: look_bagua :),
	]) );
	set("objects", ([
		__DIR__"npc/shitong":1,
		CLASS_D("taohua")+"/first": 1,
	]));
	set("valid_startroom", 1);
	set("coor/x", 9010);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	"/clone/board/taohua_b"->foo();
}

string look_bagua()
{
	int i, j, temp;
	int *bagua = ({0,1,2,3,4,5,6,7});
	string *bagua_name = ({"坤","震","坎","兌","艮","離","巽","乾"});
	string result;
	object me = this_player();

	for (i = 0; i < 8; i++)
	{
		j = random(8);
		while (j == i)
			j = random(8);
		temp = bagua[i];
		bagua[i] = bagua[j];
		bagua[j] = temp;
	}		
	for (i = 1; i < 9; i++)
		me->set_temp("bagua_" + i, bagua[i - 1]);
	result = "一個奇怪的鐵八卦，上面按順時針順序排列着：";
	for (i = 0; i < 8; i++)
		result += bagua_name[bagua[i]];
	return result + "。\n";
}

