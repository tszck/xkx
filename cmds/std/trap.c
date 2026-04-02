// trap.c 掘地為牢
// Last Modified by winder on Jul. 12 2002
inherit F_CLEAN_UP;

#include <ansi.h>


void digging(object, int);
void create() { seteuid(getuid()); }

mapping default_dirs = ([
	"north":        "北",
	"south":        "南",
	"east":         "東",
	"west":         "西",
	"northup":      "北邊",
	"southup":      "南邊",
	"eastup":       "東邊",
	"westup":       "西邊",
	"northdown":    "北邊",
	"southdown":    "南邊",
	"eastdown":     "東邊",
	"westdown":     "西邊",
	"northeast":    "東北",
	"northwest":    "西北",
	"southeast":    "東南",
	"southwest":    "西南",
	"up":           "上",
	"down":         "下",
	"out":          "外",
	"enter":        "裏",
]);
string *place = ({ "寺", "廟", "店", "樓", "鋪", "閣", "祠", "屋", 
"院", "門", "街", "莊", "齋", "橋", "社", "園", "館", "堂", "室", 
"廳", "房", "寓", "庫", "殿", "營", "廄" ,"船","舟","坪"});

int main(object me, string arg)
{
	object roomfrom, roomto, roomtrap, *inv, tool;
	mapping exits;
	string dir/*, from, to*/, *dirs;
	int i, depth;

	if( me->query("shen") >= 0 && !wizardp(me))
		return notify_fail("你出身正派，竟敢打這種歪門邪道的主意？！\n");
	if( me->query("combat_exp") >= 100000 && !wizardp(me))
		return notify_fail("如此下三爛的把戲，象你這樣的高手不屑為之吧？！\n");
	if( me->query_skill("digging", 1) <= 30)
		return notify_fail("你這點本事都沒學全，如何會挖掘陷阱？\n");
	if( me->is_fighting() )
		return notify_fail("一邊打架一邊挖掘？你真是活膩了！\n");
	if( me->is_busy() )
		return notify_fail("你現在正忙着！\n");
		tool= present("shenlong qiao", me);
	if(!tool && !wizardp(me))
      return notify_fail("先得找把趁手的工具吧？\n");
	if( !tool->query("dig_times") )
		return notify_fail("得找把趁手的工具吧?\n");
	if( tool->query("dig_times") == 1)
	{
		message_vision(GRN "\n$N偷偷摸摸地舉起鐵鍬，一鍬挖下去，“啪”地一聲木柄斷了。。。\n\n" NOR, me);
		tool->unequip();
		tool->reset_action();
		tool->set("name", tool->query("name") + "的破片");
		tool->move(environment(me));
		tool->set("value", 0);
		tool->set("weapon_prop", 0);
		tool->set("id", "tie qiao");
	}
	inv = all_inventory(environment(me));
	if( sizeof(inv) > 0)
	for(i=0; i<sizeof(inv); i++)
	{
		if( userp(inv[i]) && inv[i] != me )
			return notify_fail("膽子這麼大？現在可有旁人在場，不能挖！\n");
	}
	if( !arg || !environment(me)->query("exits/" + arg) )
		return notify_fail("你往哪個方向設陷阱？\n");
	if( strsrch(arg, "jump") >= 0  
//	||
//		strsrch(arg, "up") >= 0 ||
//		strsrch(arg, "down") >= 0 ||
//		strsrch(arg,"out") >=0 ||
//		strsrch(arg,"enter") >=0 
         )
		return notify_fail("你不能往這個方向設陷阱！\n");
	if( !environment(me)->query("trap_room") )
		roomfrom = environment(me);
	else return notify_fail("你不能在陷阱之內再設陷阱！\n");
	if( !roomfrom->query("outdoors"))
		return notify_fail("你不能這裏挖掘陷阱！\n");
	if( sizeof(roomfrom->query("exits")) >= 4 )
		return notify_fail("這裏是通衢大道，你不能此亂挖陷阱！\n");
/*
	if( roomfrom->query("cost") <= 1 )
		return notify_fail("此處土質堅實，似乎難以挖掘陷阱！\n");
*/
	if(!( roomto = find_object(roomfrom->query("exits/" + arg)) ) )
		roomto = load_object(roomfrom->query("exits/" + arg));
	if( roomto->query("trap_room") )
		return notify_fail("那邊已經有了個陷阱！\n");
	if( !roomto->query("outdoors"))
		return notify_fail("你不能在別人房門口亂挖！\n");
	for (i=0; i<sizeof(place); i++)
		if( strsrch(roomfrom->query("short"), place[i]) >= 0 ||
			strsrch(roomto->query("short"), place[i]) >= 0)
			return notify_fail("這裏的路面不適合挖陷阱！\n");

	depth = me->query_skill("digging", 1)*10
		+ me->query_str()*2 
		+ me->query_int()*2 
		+ me->query_kar()*2
		+ me->query("qi")/2;

	if( me->query("qi") < depth * roomfrom->query("cost") / 10 )
		return notify_fail("你的力氣不夠了！\n");
	roomtrap = new("/clone/misc/traproom");
	roomtrap->set("depth", depth/3 + random(depth*2/3));
	roomtrap->set("owner", me);
	roomtrap->set("limit", me->query_skill("digging", 1)/10);
	roomtrap->set("roomfrom", roomfrom);
	roomtrap->set("from", arg);

	if( !undefinedp(default_dirs[arg]) ) dir = default_dirs[arg];
	else dir = arg;
	if(objectp(roomfrom))
		roomfrom->set("exits/" + arg, file_name(roomtrap));
	if(objectp(roomto))
	{
		if( strsrch(arg, "up") >= 0 || strsrch(arg, "down") >= 0 )
			roomtrap->set("exits/" + arg, file_name(roomto));
		else roomtrap->set("exits/" + arg + "up", file_name(roomto));
		roomtrap->set("roomto", roomto);
		exits = roomto->query("exits");
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
		{
			if( exits[dirs[i]] == file_name(roomfrom) )
			{
				roomto->set("exits/" + dirs[i], file_name(roomtrap));
				roomtrap->set("exits/" + dirs[i] + "up", file_name(roomfrom));
				roomtrap->set("to", dirs[i]);
				break;
			}
		}
	}

	if(objectp(roomfrom) && objectp(roomto))
	{
		roomfrom->set("exits/jump" + roomtrap->query("from"), file_name(roomto));
		roomto->set("exits/jump" + roomtrap->query("to"), file_name(roomfrom));
	}

	message_vision(GRN "\n$N偷偷摸摸地舉起鐵鍬，朝着" + dir + "方猛挖一通。。。\n\n" NOR, me);
	tool->add("dig_times", -1);
	remove_call_out("digging");
	call_out("digging", depth/100, me, depth);
	me->start_busy(depth/100);

	return 1;
}

void digging(object me, int depth)
{
	if( me->is_busy() )
	{
		call_out("digging", 3, me, depth);
		if(random(5)==1) message_vision(GRN "\n$N起勁地往地下挖着挖着。。。\n" NOR, me);
	}
	else	
	{
		me->improve_skill("digging", depth / 20);
		me->receive_damage("qi", depth * (environment(me))->query("cost") / 10, "挖陷阱累死了");
		tell_object(me, "你大汗淋漓地挖好了一個陷阱！\n");
	}
}

int help (object me)
{
	write(@HELP
指令格式 : [trap <方向>]

這個指令讓你向某個方向挖掘一個陷阱。

HELP
);
	return 1;
}