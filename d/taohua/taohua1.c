// Room: /d/taohua/taohua1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	int thd1, thd2, thd3, thd4;

	thd1 = random(4) + 1;
	thd2 = random(4) + 1;
	thd3 = random(4) + 1;
	thd4 = random(4) + 1;
	while (thd1 != 4 && thd2 != 4 && thd3 != 4 && thd4 != 4) {
		thd1 = random(4) + 1;
		thd2 = random(4) + 1;
		thd3 = random(4) + 1;
		thd4 = random(4) + 1;
	}
	set("short", "桃花陣");
	set("long", @LONG
這裏是一片桃花的海洋。四周一望無際，全是盛開的桃花。微風拂
過，落英繽紛。周圍靜悄悄的。遠處偶爾傳來一聲鳥叫。你心中不禁慌
亂起來：還是早點出去的好。
LONG
	);

	set("exits", ([
		"east" : __DIR__"taohua" + thd1,
		"west" : __DIR__"taohua" + thd2,
		"south" : __DIR__"taohua" + thd3,
		"north" : __DIR__"taohua" + thd4,
	]));
	set("no_drop","1");
	set("coor/x", 9010);
	set("coor/y", -3090);
	set("coor/z", 0);
	setup();
}

void init()
{
	object letter, ob=this_player();

	if ((ob->query("family/family_name") == "桃花島" && ob->query_skill("count", 1) > 19) ||
		ob->query_skill("qimen-wuxing", 1) > 29)
		{
		write("由於你平常看慣了這些簡易的陣法，所以不用細想，信步就走出了陣！\n");
		ob->move(__DIR__"xiaoyuan", 1);
		tell_room(environment(ob), "卻見花影閃爍，樹叢忽然現出一個缺口，" + ob->name() + "閃身而出。\n", ({ob}));
		return;
	}
	if ((letter = present("recommend letter", ob)) && letter->query("owner") == ob->query("id")) {
		write( "你正在疑惑怎麼穿過這個桃花陣，一個作僕役打扮的啞巴忽然走了出來，檢查了你身上的推薦信後示意你跟着他走。\n");
		write( "沒過多久，你們就穿過了桃花陣，經過一個小小的院落後來到一座亭子跟前。\n");
		ob->move(__DIR__"jicui", 1);
		tell_room(environment(ob), "一個啞僕領着" + ob->name() + "走了過來。\n", ({ob}));
		return;
	}
	if (ob->query_temp("step_count") > 99) {
		ob->delete_temp("step_count");
		write("你在陣中累得精疲力盡，終因體力不支而昏了過去！\n");
		write( "迷迷胡胡中似乎有人把你抬出了陣，彷彿有個威嚴的聲音喝道：“扔到海里去”。\n");
		ob->unconcious();
		ob->move(__DIR__"shore", 1);
		message("vision","忽然一個大潮湧了過來，將一個被水泡得半死的傢伙衝到了岸邊。\n", environment(ob), ob);
		return;
	}
	ob->add_temp("step_count", 1);
}

