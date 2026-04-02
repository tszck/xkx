// room: /d/lingjiu/jian.c
// modified by rocwood
#include <ansi.h>
inherit ROOM;
void init();
int do_zou(string);
int do_jump(string);
string check_tiesuo();
void create()
{
	set("short","百丈澗");
	set("long",@LONG
山道到此突然消失，在你面前是一條山澗(shanjian)，山澗之中雲
霧繚繞，你根本無法看清對面。一條鐵索(tiesuo)深入雲中，旁邊有一
塊石碑(bei)。
LONG );
	set("outdoors", "lingjiu");
	set("exits",([
		"southdown" : __DIR__"yan",
	]));
	set("objects",([
		__DIR__"npc/yupopo" : 1,
	]));
	set("item_desc",([
		"shanjian" : "山澗之中雲霧繚繞，你根本無法看清對面，也許可以運氣跳(jump)過去。\n",
		"bei"      : "『靈鷲宮』重地，擅入者死！\n",
		"tiesuo"   : (: check_tiesuo :),
	]));
	set("coor/x", -51010);
	set("coor/y", 30010);
	set("coor/z", 50);
	setup();
}
void init()
{
	add_action("do_zou", "zou");
	add_action("do_jump","jump");
}
int do_zou(string arg)
{
	object me=this_player(), room;
	if(!arg || arg!="tiesuo") return notify_fail("你要走什麼？\n");
	if (me->is_busy()) return notify_fail("你正忙着呢。\n");
	if(!( room = find_object(__DIR__"xianchou")) )
		room = load_object(__DIR__"xianchou");
	if(!objectp(room))
		return notify_fail("ERROR:not found 'xianchou.c' 請巫師處理\n");
	if(objectp(present("yu popo", environment(me))))
	{
		if ((string)me->query("family/family_name")!="逍遙派"
		&& (string)me->query("family/family_name")!="靈鷲宮"
		)
			message_vision("餘婆婆伸手攔住$N，説道：“老身奉主人之命守衞百丈澗，\n非靈鷲宮弟子請回！”\n",me);
		else
		{
			message_vision(HIW"$N輕輕躍起踩上鐵索，瀟灑地向對面走去。\n\n"NOR,me);
			me->move(room);
		}
	}
        else message_vision("$N看着斷掉的鐵索，不禁發愁，怎麼過去呢？\n",me);
        return 1;
}
int do_jump(string arg)
{
	object me=this_player(), room, room1;
	int n = (int)this_player()->query_skill("dodge",1);
	if(!arg || arg!="shanjian") return notify_fail("你要往哪裏跳？\n");
	if (me->is_busy()) return notify_fail("你正忙着呢。\n");
	if(!( room = find_object(__DIR__"xianchou")) )
		room = load_object(__DIR__"xianchou");
	if(!objectp(room))
		return notify_fail("ERROR:not found 'xianchou.c' 請巫師處理\n");
	if(!( room1 = find_object(__DIR__"shanjiao")) )
		room1 = load_object(__DIR__"shanjiao");
	if(!objectp(room1))
		return notify_fail("ERROR:not found 'shanjiao.c' 請巫師處理\n");
	if(objectp(present("yu popo", environment(me))))
		message_vision("犯什麼傻，不是有鐵索可以走過去嗎？跳什麼跳呀！\n", me);
	else
		if ((string)me->query("family/family_name")=="逍遙派")
		{
			message_vision( HIW"$N長髮一甩，運起靈鷲宮獨門輕功，輕輕躍起，瀟灑地向對面飄去。\n\n"NOR,me);
			me->move(room);
		}
		else
		{
			message_vision( HIW"$N運起輕功，向對面躍去。\n"NOR,me);
			message_vision( HIW"不料距離山澗對面相當遠，$N一口真氣提不上來，眼看向山下掉下去。\n"NOR,me);
			if(n>100)
			{
				message_vision( HIY"$N急中生智，抓住對面垂下的那一截斷鐵索，借力向上躍去。\n"NOR,me);
				message_vision(HIY"$N暗暗叫到：好險！\n"NOR,me);
				me->move(room);
			}
			else
			{
				message_vision(HIR"$N手忙腳亂，發出刺耳的慘叫聲！\n"NOR, me);
				message_vision(HIR"$N重重地跌到了山腳下……\n\n"NOR, me);
				me->move(room1);
				me->receive_damage("qi", 500);
				me->receive_wound("qi", 500);
			}
		}
	return 1;
}
string check_tiesuo()
{
	object me=this_player();
	if((objectp(present("yu popo", environment(me)))))
		return "這是通往對面的“接天橋”，你也許可以走過(zou)去。\n";
	else return "看來鐵索已經斷了，怎麼過去呢？\n";
}

