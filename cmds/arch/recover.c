// recover.c
inherit F_CLEAN_UP;

#include <login.h>
#include <obj.h>



int main(object me, string arg)
{
    object *ob;
    string wiz_status, src, dst, playerid;
    object link_ob;
    int i;

    if( me != this_player(1) ) return 0;

    wiz_status = SECURITY_D->get_status(me);
    if( wiz_status != "(admin)" && wiz_status != "(arch)" )
        return notify_fail("只有 (arch) 以上的巫師才能恢復被封住的時空\n");

    seteuid(getuid());
    message("system", "\n*** " + RANK_D->query_rank(me) + me->short(1) + "正在將被鎖時空解封 ***\n*** 世界好象正在慢慢恢復成以前的樣子... ***\n", users());
        write("處理中：");

    ob = users();
    for(i=0; i<sizeof(ob); i++) {
        if( objectp(link_ob = ob[i]->query_temp("link_ob")) ) {
            playerid = ob[i]->query("id");
            dst = "/data/user/" + playerid[0..0] + "/" + playerid + ".o" ;
            src = "data/keep/" + playerid ;

            cp(src, dst);
            rm(src);
            ob[i]->restore();
        }
//		else {
//			return notify_fail("時空解封失敗了！！n?);
//		}
    }

    write("時空解封完畢。\n");
    LOGIN_D->set_madlock(0);
        //wind try
    log_file("/static/RECOVER", sprintf("%s call recover ON %s.\n", this_player()->query("name"),ctime(time())));
    return 1;
}

int help (object me)
{
    write(@HELP
指令格式: recover

解封被封住的時空。

HELP
);
    return 1;
}
