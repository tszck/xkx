// Room: /d/taohua/bagua1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "八卦桃花陣");
	set("long", @LONG
這是一片茂密的桃花叢，你一走進來就迷失了方向。眼前是一排桃
花樹，密密地沒有一絲縫隙。
LONG
	);
	set("outdoors","taohua");
	set("exits", ([
		"east" : __DIR__"bagua0",
		"west" : __DIR__"bagua0",
		"south" : __FILE__,
		"north" : __FILE__,
	]));
	set("coor/x", 8800);
	set("coor/y", -3500);
	set("coor/z", 0);
	setup();
}

void init()
{
	object ob=this_player();
	int step, temp, count;

/*	if (!ob->query_temp("bagua_1")) {
		write("你感覺這個桃花陣中暗藏八卦，隱隱生出阻力，將你推了回來！\n");
		ob->move(__DIR__"xiaoyuan", 1);
		return;
	}*/
	if (ob->query_skill("qimen-wuxing", 1) > 99) {
		write("由於你已經精研了九宮八卦的變化，所以略做思考就走出了陣！\n");
		ob->move(__DIR__"road1", 1);
		tell_room(environment(ob), "卻見花影閃爍，樹叢忽然現出一個缺口，" + ob->name() + "閃身而出。\n", ({ob}));
		return;
	}
	if (!ob->query_temp("bagua_start")) {
		ob->set_temp("bagua_start", 1);
		ob->set_temp("bagua_step", 1);
		ob->set_temp("bagua_temp", 0);
		ob->set_temp("bagua_count", 1);
	}
	temp = ob->query_temp("bagua_temp");
	count = ob->query_temp("bagua_count");
	temp = temp * 2 + 1;
	if (count < 3) {
		count++;
	}
	else
	{
		count = 1;
		step = ob->query_temp("bagua_step");
		if (temp == ob->query_temp("bagua_" + step)) {
			if (step == 8) {
				ob->delete_temp("bagua_start");
				ob->delete_temp("bagua_step");
				ob->delete_temp("bagua_temp");
				ob->delete_temp("bagua_count");
				write("你倒踩八卦，直撲生門，眼前現出一道門戶，你趕忙踏了過去。\n");
				ob->move(__DIR__"road1", 1);
				tell_room(environment(ob), "卻見花影閃爍，樹叢忽然現出一個缺口，" + ob->name() + "閃身而出。\n", ({ob}));
				return;
			}
			write("你發現剛才走過的路徑暗合八卦，心中若有所悟！\n");
			ob->add_temp("bagua_step", 1);
		}
		else {
			ob->delete_temp("bagua_start");
			ob->delete_temp("bagua_step");
			ob->delete_temp("bagua_temp");
			ob->delete_temp("bagua_count");
			write("你發覺自己踩錯了方位，四周暗霧密佈，只好趕快搶回起始點！\n");
			ob->move(__DIR__"xiaoyuan", 1);
			tell_room(environment(ob), "卻見花影閃爍，樹叢忽然現出一個缺口，" + ob->name() + "踉蹌着退了出來。\n", ({ob}));
			return;
		}
		temp = 0;
	}
	ob->set_temp("bagua_temp", temp);
	ob->set_temp("bagua_count", count);
}
