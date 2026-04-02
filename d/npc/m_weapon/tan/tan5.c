//tan5.c

inherit ROOM;
void init();
int do_push(string);
void create()
{
	set("short", "嘉興南湖 ");
	set("long",
		"這裏是嘉興南湖底，四周黑忽忽的，頭頂上看不見一點亮光，身邊的水流\n"
		"忽上忽下的湧動着。看起來是一處海眼。東邊似乎有一點亮光，被一塊巨大\n"
		"的石塊(stone)擋着。周圍一片死寂，似乎暗藏着層層殺機。\n"

	);
	set("exits", ([
		"up" : __DIR__"tan6",	
		"west" : __DIR__"tan7",
		"south" : __DIR__"tan7",
		"north" : __DIR__"tan7",
	]));
	set("item_desc", ([
		"stone": 
"\n這是一塊巨大的石頭，看起來質地是玄武岩的，顯得十分的堅硬。你用手試着推了一把\n"
"(push)，石頭動了一下，馬上又回到原地了。從移開一瞬間，你恍惚看見幾縷光線從裏\n"
"面投射出來。看來裏面一定別有一番洞天。\n"
	]) );
	set("no_clean_up", 0);
	set("coor/x", -1520);
	set("coor/y", -1020);
	set("coor/z", -40);
	setup();
}

void init()
{	
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();
	object room;

	if ((arg !="stone" || !arg))
		return notify_fail("你要推什麼？\n");
	if ((int)me->query_skill("dodge") < 50 ) {
		me->add_temp("tmark/金",1);
		write("忽然一道暗流衝來，你腳下一個踉蹌，大叫一聲：不好！\n");
		message("vision","前面的人影身行猛然一晃，急劇向下墜去。看來是凶多吉少了!\n",
			environment(me), ({me}) );
		me->unconcious();
		me->move("/d/taohua/haitan");
		message_vision("海浪一陣翻湧，砰的一個人被拋了上來。\n", me);
		return 0;
	}
	
	if (!( room = find_object(__DIR__"cave")) )
		room = load_object(__DIR__"cave");
	if (!query("exits/east"))
		{
		set("exits/east", __DIR__"cave");
		message_vision("$N把巨石推到一邊，露出一個洞口，裏面幽幽的有些光亮。\n",me);
		room -> set("exits/west", __FILE__);
		message("vision", "外面傳來一陣移動巨石的隆隆的響聲。\n",room);
		}
	else
	{
		delete("exits/east");
		message_vision("水流一陣湧動，巨石轟隆一聲滾回了原處，洞口又被封住了。\n",me);
		room -> delete("exits/west");
		message("vision","外面傳來一聲巨響，洞口被封住了。\n", room);
	}
	return 1;
}
