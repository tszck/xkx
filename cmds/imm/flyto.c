// flyto.c

inherit F_CLEAN_UP;

#include <ansi.h>
#include <command.h>


int main(object me, string arg)
{
//      string home;
        int goto_inventory = 0;
        object obj;
//      string msg;
        if( !arg ) return notify_fail("你要往哪兒飛？\n");

        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        if( !arg ) return notify_fail("你要飛到哪兒去？\n");

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if(!obj || !me->visible(obj)) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                return me->move(arg);
                        return notify_fail("沒有這個玩家、生物、或地方。\n");
                }
        }

        if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail("這個物件沒有環境可以 flyto。\n");
         tell_object(me,"咦，怎麼還不起飛呢？……\n");
         tell_object(me,"呵呵呵呵，飛了飛了！小小巫師飛呀飛……！\n");
         me->move(obj);

        tell_object(me,"到了？到了！降落嘍！！！\n");
        return 1;
}

int help(object me)
{write(@HELP
指令格式 : flyto [-i] <目標>
HELP);
    return 1;
}