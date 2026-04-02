// snpnpc.c
int main(object me, string arg)
{
        
        object ob,snpee;
        string snoopee;
        seteuid(getuid());
        if( !arg ) return notify_fail("你要監聽誰?\n");
        if( arg == "none" )
        {
                snoopee = me->query_temp("snoopee");
                if( !snoopee ) return notify_fail("你沒有監聽任何人.\n");
                snpee = find_player(snoopee);
                if( !snpee )
                snpee = find_living(snoopee);
                if( !snpee ) return notify_fail("找不到你所監聽的人.\n");
                snpee->set_temp("is_snooped",0);
                me->set_temp("snoopee",0);
                return notify_fail("你現在停止監聽"+snpee->name()+"所收到的信息\n");
        }
        if( me->query_temp("snoopee") )
                return notify_fail("你已經在監聽中了.\n");
        ob = find_player(arg);
        if( !ob )
                ob = find_living(arg);
        if( !ob )
                return notify_fail("找不到這個人。\n");
        ob->set_temp("is_snooped",1);
        ob->set_temp("snooper",me->query("id"));
        me->set_temp("snoopee",ob->query("id"));
        write("你現在開始監聽"+ob->name()+"所收到的信息.\n");
        return 1;
}

int help(object me)
{
   write( @HELP
指令格式: snp <someone> 開始監聽.
        或 snp none 取消監聽.
HELP
   );
   return 1;
}