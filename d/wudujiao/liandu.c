// Room: /d/wudujiao/liandu.c

inherit ROOM;

void create()
{
	set("short", "練毒室");
	set("long", @LONG
這裏是五毒教弟子專門的練毒室，可以在這裏練制各種毒藥，案上
擺着各式各樣的器具。屋內正中放着一個一人多高的丹爐，爐火正旺，
有一個黑瘦的道人正手持桃木劍繞爐疾走，嘴裏吶吶自語不知在唸些什
麼？
LONG
	);

	set("exits", ([
		"north" : __DIR__"nanyuan",
	]));
	set("objects", ([
		__DIR__"npc/daoren": 1,
	]));
	set("coor/x", -44920);
	set("coor/y", -81070);
	set("coor/z", 30);
	setup();
}

void init ()
{
	add_action("do_lianzhi","lianzhi");
}

int do_lianzhi (string arg)
{
	object ob;
	object me = this_player();
	if (arg != "red yao"&& arg!="yellow yao" && arg!="green yao" &&
		arg!="white yao"&& arg!="black yao" && arg!="shenxiandao")
		return 0;
	if (arg == "red yao")
	{
		if (!present("she dunang",me)||!present("shexin zi",me))
			return notify_fail("你身上藥品不全，無法練制。\n");
		destruct(present("she dunang",me));
		destruct(present("shexin zi",me));
		ob = new("/clone/medicine/poison/redyao");
		ob->move(me);
		message_vision ("$N將身上的藥品投入丹爐，按祕法小心練制起來！\n",me);
		tell_object(me, "藥品練製成功！\n");
	}
	if (arg == "yellow yao")
	{
		if (!present("wugong dunang",me)||!present("chuanxin lian",me))
			return notify_fail("你身上藥品不全，無法練制。\n");
		destruct(present("wugong dunang",me));
		destruct(present("chuanxin lian",me));
		ob = new("/clone/medicine/poison/yellowyao");
		ob->move(me);
		message_vision ("$N將身上的藥品投入丹爐，按祕法小心練制起來！\n",me);
		tell_object(me, "藥品練製成功！\n");
	}
	if (arg == "green yao")
	{
		if (!present("zhizhu dunang",me)||!present("fugu cao",me))
			return notify_fail("你身上藥品不全，無法練制。\n");
		destruct(present("zhizhu dunang",me));
		destruct(present("fugu cao",me));
		ob = new("/clone/medicine/poison/greenyao");
		ob->move(me);
		message_vision ("$N將身上的藥品投入丹爐，按祕法小心練制起來！\n",me);
		tell_object(me, "藥品練製成功！\n");
	}
	if (arg == "white yao")
	{
		if (!present("xiezi dunang",me)||!present("heding hong",me))
			return notify_fail("你身上藥品不全，無法練制。\n");
		destruct(present("xiezi dunang",me));
		destruct(present("heding hong",me));
		ob = new("/clone/medicine/poison/whiteyao");
		ob->move(me);
		message_vision ("$N將身上的藥品投入丹爐，按祕法小心練制起來！\n",me);
		tell_object(me, "藥品練製成功！\n");
	}
	if (arg == "black yao")
	{
		if (!present("chanchu dunang",me)||!present("duanchang cao",me))
			return notify_fail("你身上藥品不全，無法練制。\n");
		destruct(present("chanchu dunang",me));
		destruct(present("duanchang cao",me));
		ob = new("/clone/medicine/poison/blackyao");
		ob->move(me);
		message_vision ("$N將身上的藥品投入丹爐，按祕法小心練制起來！\n",me);
		tell_object(me, "藥品練製成功！\n");
	}
	if (arg == "shenxiandao")
	{
		if (!present("jinshe duye",me)||!present("qianri zui",me))
			return notify_fail("你身上藥品不全，無法練制。\n");
		destruct(present("jinshe duye",me));
		destruct(present("qianri zui",me));
		ob = new("/clone/medicine/poison/shenxiandao");
		ob->move(me);
		message_vision ("$N將身上的藥品投入丹爐，按祕法小心練制起來！\n",me);
		tell_object(me, "藥品練製成功！\n");
	}
	return 1;
}
