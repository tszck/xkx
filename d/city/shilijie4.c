// Room: /yangzhou/shiliji4.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;
look_gaoshi();

void create()
{
	set("short","中央廣場");
	set("long",@LONG
這裏是城市的正中心，一個很寬闊的廣場，鋪着青石地面，十里長
街穿場而過。一些遊手好閒的人在這裏溜溜達達，經常有藝人在這裏表
演。中央有一棵大榕樹，盤根錯節，據傳已有千年的樹齡，是這座城市
的歷史見證。樹幹底部有一個很大的樹洞(dong)。你可以看到北邊有來
自各地的行人來來往往，南面人聲鼎沸，一派繁華景象。東邊連着甘泉
街。街西是通泗橋，橋頭立着一塊告示牌(gaoshi)，過橋就是通向揚州
官衙的道路。
LONG );
	set("outdoors", "yangzhouw");
	set("no_sleep_room",1);
	set("visitor", 0);
	set("item_desc", ([
		"dong"  : "這是一個黑不溜湫的大洞，裏面不知道有些什麼古怪。\n",
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east"  : __DIR__"ganquanjie",
		"west"  : __DIR__"tongsiqiao",
		"south" : __DIR__"shilijie5",
		"north" : __DIR__"shilijie3",
		"down"	: __DIR__"lajichang",
	]));
	set("objects", ([
//		__DIR__"npc/xunbu" : 1,
		__DIR__"npc/liumang" : 4,
		__DIR__"npc/liumangtou" : 1,
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

void init()
{
	if(userp(this_player()))
	{
		this_object()->add("visitor", 1);
		if(this_object()->query("visitor") % 500 == 0)
		{
			AUTOSAVE_D->create();
		}
	}
	add_action("do_enter", "enter");
//	UPDATE_D->check_user(this_player());
}

int do_enter(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="dong" )
	{
		if (me->is_busy()) return notify_fail("你正忙着呢。\n");
		message("vision",
			me->name() + "一彎腰往洞裏走了進去。\n",
			environment(me), ({me}) );
		me->move("/d/gaibang/inhole");
		message("vision",
			me->name() + "從洞外走了進來。\n",
			environment(me), ({me}) );
		return 1;
	}
}

string look_gaoshi()
{
	string returnback;
	int count, sp;
	count=query("visitor");
	returnback="\n\n"+
	"******************************************************************\n"+
	"********                                                  ********\n"+
	"********                    揚州府通告                    ********\n"+
	"********                                                  ********\n"+
	"********    即日通過此地共有"+chinese_number(count)+"人。";
	for (sp = 0; sp < 26-strwidth(chinese_number(count)); sp++)
		returnback += " ";

	returnback += "********\n"
	"********                                                  ********\n"+
	"******************************************************************\n";
	return returnback;
}
