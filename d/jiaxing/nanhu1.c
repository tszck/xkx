// Room: /d/jiaxing/nanhu1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void init();
int do_out();

void create()
{
	set("short", "嘉興南湖");
	set("long", @LONG
這裏是煙波浩淼的南湖。湖上幾隻畫舫在遊蕩，船上的遊客和青樓
女子在嘻笑。湖水很深，沒有船是渡不過去的。但不知是誰在湖底釘了
一些木樁。樁頂潛在水面之下一兩寸的地方。即使是不懂輕功的人走上
去也像是水上漂的樣子。似乎水下有了些什麼。近來有人潛 (out)下湖
去搜尋什麼, 總也不知道結果如何。只是有人傳聞在湖底找到了什麼寶
貝。
LONG );
	set("exits", ([
		"south"     : __DIR__"yanyu",
		"northwest" : __DIR__"nanhu",
		"southeast" : __DIR__"road",
	]));
	set("outdoors", "jiaxing");
        set("objects", ([
                "/clone/medicine/vegetable/heye" : random(2),
        ]));
	set("coor/x", 1520);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_out","out");
}

int do_out()
{
	object me = this_player();
	message_vision("$N縱身躍起，空中一個浪裏翻花，頭下腳上，咚的一聲潛入湖中不見了.\n", me);
	me->move("/d/npc/m_weapon/tan/tan1");
	return 1;
}