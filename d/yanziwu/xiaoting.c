// Room: xiaoting

#include <ansi.h>
inherit ROOM;

void init();
int do_tap(string);
int do_sit(string);
void delete_served(object);

void create()
{
	set("short", "曉寒廳");
	set("long", @LONG
這是一間小廳，廳雖不大，佈置倒也別緻。滿廳的芳香，沁人心脾。
只見牆上掛着幾幅條幅，筆致頗為瀟灑，但掩不住幾分柔弱之氣。廳內
四周精巧地擺着些桌子(table)和椅子(chair)。
LONG );
	set("exits", ([
		"west" : __DIR__"qinyun",
		"east" : __DIR__"cuixia",
		"north" : __DIR__"xiaojing",
		"south" : __DIR__"chufang",
	])); 
	set("item_desc", ([
		"table" : "一張典雅的桃木小桌，上面放着水果盤和飲茶器具。\n",
		"chair" : "一隻青竹打製的靠椅，躺上去搖搖晃晃，好舒服耶！\n",
	])); 
	set("objects",([
		__DIR__"npc/susu" : 1,
		__DIR__"obj/gao" : 2,
		__DIR__"obj/cha" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 820);
	set("coor/y", -1500);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_tap", "tap");
	add_action("do_tap", "knock");
	add_action("do_sit", "sit");
}

int do_tap(string arg)
{

	object me;
	object susu;

	if (!arg || (arg != "desk" && arg != "table"))
	{
		return notify_fail("你要敲什麼？\n");
	}

	me = this_player();
	if( !objectp(susu = present("susu", environment(me))) )
		return notify_fail("你敲了敲桌子，卻還是沒人理你。你突然感覺自己很無聊。\n");

	if( !me->query_temp("marks/sit") )
		return notify_fail("你敲了敲桌子，卻沒想到段譽和王語嫣從桌底下鑽出來，滿\n臉通紅生氣地看着你，你突然感覺自己很愚蠢。\n");

	if( me->query_temp("marks/served") )
	{
		message_vision("素素不耐煩地對$N説道：剛給你上過茶你接着就要，"+
			"你是個Ｒｏｂｏｔ我可不是啊！\n", me);
		return notify_fail("");
	}

	message_vision("$N端坐在桌前，輕輕釦了下桌面，素素一笑，過來招呼。\n", me);
	susu->serve_tea(me) ; 
	me->set_temp("marks/served", 1);
	call_out("delete_served", 10, me);

	return 1;
}


void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}


int do_sit(string arg)
{

	if ( !arg || (arg != "chair") )
		return notify_fail("你要坐什麼上面？\n");

	if (this_player()->query_temp("marks/sit"))
		return notify_fail("你已經有了個座位了。\n");

	this_player()->set_temp("marks/sit", 1);
	return notify_fail("你找了個空位座下，等着上茶。\n");
}


int valid_leave(object me,string dir)
{
 //     if ( (dir =="north") ||(dir==south)||(dir==east)||(dir==west) )
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return::valid_leave(me,dir);
}