// who.c
// From ES2
// Modified by Java on Sep.14 1998
// Commedted by Spacenet on Nov.4 1999
// Modified by Zeratul on Mar.26 2000
inherit F_CLEAN_UP;

#include <ansi.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/macros.h>


string *faction_name = ({
	"少林派",
	"南少林派",
	"武當派",
	"峨嵋派",
	"青城派",
	"崑崙派",
	"嵩山派",
	"泰山派",
	"華山派",
	"衡山派",
	"恆山派",
	"星宿派",
	"丐幫",
	"明教",
	"神龍教",
	"大理段家",
	"桃花島",
	"白駝山派",
	"姑蘇慕容",
	"全真教",
	"古墓派",
	"雪山寺",
	"逍遙派",
	"靈鷲宮",
	"凌霄城",
	"雲龍門",
	"紅花會",
	"黑木崖",
	"五毒教",
	"鐵掌幫",
});
int sort_user(object,object);
int visiblep(object);
int help();

void create() {  seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
        string name, str, *option;
        object *list, *ob, ob1;
	int i, j, ppl_cnt, fac_no, fac_amt = sizeof(faction_name);
        int opt_long, opt_wiz, opt_party ,opt_age, opt_exp;

        if( arg ) {
                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) {
                                case "-h": return help();
                                case "-l": opt_long = 1;        break;
                                case "-w": opt_wiz = 1;         break;
//                              case "-f":
                                case "-p": opt_party = 1;       break;
                                case "-a": opt_age = 1;         break;
  //                              case "-e": opt_exp = 1;         break;
                                //如果不帶以上幾種參數，則為who + player_id情況
                                default:

                                       if(option[i][0]=='@' ) {
                                       	      if (option[i][1..sizeof(option[i])-1]!=mud_nname())
                                       	      {
                                                RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])-1],
                                                        //me, opt_long);
                                                        me, replace_string(arg,option[i],""));
                                                write("網路訊息已送出，請稍候。\n");
                                                return 1;
                                              }
                                              else
                                              {
                                              	return main(this_player(),replace_string(arg,option[i],""),remote);
                                              	}
                                        }
                                        //先於該玩家所處的環境中找尋被查玩家。
                                        ob1 = present(option[i], environment(me));
                                        //如果沒找到，則在所有玩家列表中找尋。
                                        if (!ob1) ob1 = find_player(option[i]);
                                        //如果還是沒找到，則在所有生物列表中找尋。
                                        if (!ob1) ob1 = find_living(option[i]);
                                        if (!ob1)
                                        {
                                        	list = users();
                                         	for(j=0;j<sizeof(list);j++)
                                         	{
                                         	 if (list[j]->query("name") == option[i])
                                         	   {ob1 = list[j];break;}
                                         	}
                                        }
                                        if (!ob1) return notify_fail("沒有這個玩家或參數錯誤。\n指令格式 : who [-h] [-l] [-w] [-p] [<ID>]\n");
                                       // if ( objectp(this_player()) && userp(this_player())&& !wizardp(this_player()) && !this_player()->visible(ob1))
                                        if ( objectp(me) && userp(me) && !wizardp(me) && !me->visible(ob1))
                                        	return notify_fail("沒有這個玩家或參數錯誤。\n指令格式 : who [-h] [-l] [-w] [-p] [<ID>]\n");
                                        /* 由於下面這行，使得當who + 巫師名時，無論該巫師隱身與否，玩家都能
                                           看見，加了上面這行便避免了這種情況的發生。Modified by Spacenet */
                                        me = ob1; opt_party = 1;
                        }
        }

        if( objectp(me) && userp(me) && opt_long && !wizardp(me)) {
                if( (int)me->query("jing") < 5 )
                        return notify_fail("你的精神太差了，沒有辦法得知其他玩家的詳細資料。\n");
                me->receive_damage("jing", 5);
        }
	//根據不同的參數設置表頭。
        str = HIG "◎"+MUD_NAME+HIG "◎"+HIW+"    目前江湖中的 " NOR;
        if(opt_party)
                if(me->query("family/family_name"))
                        str += HIR+"("+me->query("family/family_name")+") "+NOR;
                else str += HIR + "(無門派) " + NOR;
        if ( opt_wiz )
                str += "神仙有：";
        else
                if ( opt_long ) str += "玩家有：";
                else str += "總人物有：";

        str += "\n";
        str +=
                HIC"≡"+HIY"----------------------------------------------------------------------"HIC"≡\n"NOR;
        ob = filter_array( objects(), (: visiblep :) );
        if (opt_party) {
               //在數組ob中找尋符合party指定的同門玩家。
               ob = filter_array(ob, (: $1->query("family/family_name") ==
                        $2->query("family/family_name") :), me);
                        }
        list = sort_array(ob, (: sort_user :));
        ppl_cnt = 0;   //ppl_cnt ?= party player count（同門玩家數）。

        //處理who -l的情況。
        if( opt_long )
        {
               //按照門派分類列出玩家。
               for (fac_no=0; fac_no<fac_amt; fac_no++)
               {
                       i = sizeof(list);
                       while ( i-- )
                       {
                                if( interactive(list[i]) )
                                	ppl_cnt++;
                                //把同門的玩家列在一起。
                                if( list[i]->query("family/family_name") == faction_name[fac_no])
                                        str = sprintf("%s%12s%s%s\n",
                                                str,
                                                RANK_D->query_rank(list[i]),
                                                //根據玩家當前狀態（發呆，斷線）分別加上不同標誌。
                                                interactive(list[i])?(query_idle(list[i]) > 150? HIG "*" NOR:" "):HIR "#" NOR,
                                                list[i]->short(1));
			}
                }
                //處理無門派玩家。
                i = sizeof(list);
                while ( i-- )
                {
                        if( interactive(list[i]) )
                        ppl_cnt++;
                        if(!list[i]->query("family") )
                                str = sprintf("%s%12s%s%s\n",
                                        str,
                                        RANK_D->query_rank(list[i]),
                                        interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                        list[i]->short(1));
                }
        } else  if( opt_wiz )  //處理who -w的情況。
                {
                        i = sizeof(list);
                        while( i-- )
                        {
                                if (interactive(list[i]))
                                ppl_cnt++;
                                if (!wizardp(list[i]) ) continue;
                                if (list[i]->query("no_look_wiz")) continue;
                                str = sprintf("%s%12s%s%s\n",
                                        str,
                                        RANK_D->query_rank(list[i]),
                                        interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                        list[i]->short(1));
                        }
        } else  if( opt_exp )  //處理who -e的情況。
                {
                	      list = sort_array(list,(: $1->query("combat_exp") - $2->query("combat_exp") :));
                        i = sizeof(list);
                        while( i-- )
                        {
                            //    if (interactive(list[i]))
                            //    ppl_cnt++;
                                if (wizardp(list[i]) && !list[i]->query("no_look_wiz")) continue;
                                str = sprintf("%s%12s%s%s\n",
                                        str,
                                        RANK_D->query_rank(list[i]),
                                        interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                        list[i]->short(1));
                        }
                } else  //處理其他情況。
                {
                i = sizeof(list);
                while ( i-- )
                        {
                        if( interactive(list[i]) && wizardp(list[i]) && !list[i]->query("no_look_wiz") )
                                        name = sprintf( "%s"HIM"%-10s(%-11s"HIY"│",
                                                        " ",
                                                        list[i]->name(1),
                                                        capitalize(list[i]->query("id"))+")");
                        else if( interactive(list[i]) && query_idle(list[i]) > 150)
                                        name = sprintf( "%s%-10s(%-11s"HIY"│",
                                                        HIG"*"HIW,
                                                        list[i]->name(1),
                                                        capitalize(list[i]->query("id"))+")");
                        else if(list[i]->query_temp("netdead"))
                                        name = sprintf( "%s%-10s(%-11s"HIY"│",
                                                        HIR"#"HIW,
                                                        list[i]->name(1),
                                                        capitalize(list[i]->query("id"))+")");
                        else
                                        name = sprintf( HIW"%s%-10s(%-11s"HIY"│",
                                                        " ",
                                                       list[i]->name(1),
                                                       capitalize(list[i]->query("id"))+")");
                                        str = sprintf("%s%25s%s", str, name,
                                                ppl_cnt%3==2?"\n":"");
//                                        if (interactive(list[i]))
                                                ppl_cnt++;
                }
                if ( ppl_cnt%3 ) str += "\n";
        }

        str += HIC"≡"+HIY"----------------------------------------------------------------------"HIC"≡\n"NOR;
        str = sprintf("%s共有 %s 位使用者連線中，系統負擔：%s\n "HIG"*"NOR" 表示發呆中，"HIR"#"NOR" 表示斷線中。", str, CHINESE_D->chinese_number(sizeof(list)),
                query_load_average());

        if( remote ) return str+"\n";
//      write(str + "\n");
        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2)
			- (int)SECURITY_D->get_wiz_level(ob1);

	return (int)ob2->query("family/generation") - (int)ob1->query("family/generation");
}

int visiblep( object ob )
{
	if ( userp(ob) && environment(ob) ) {
    if( !objectp(this_player()) || !userp(this_player()))
    {
      	if (!wizardp(ob)) return 1;
      	else if (!ob->query("env/invisibility")) return 1;
      	else return 0;
    }
		if(  wizardp(this_player()) ) return 1;
		if( !wizardp(this_player()) && this_player()->visible(ob) ) return 1;
	}
	return 0;
}
int help()
{
//write(@HELP
write("
指令格式 : who [-h] [-l] [-w] [-p] [<ID>]

    這個指令可以列出所有在線上的玩家及其等級。

-h 列出幫助屏幕。
-l 選項列出較長的訊息。
-p 只列出同門的玩家。
-w 只列出線上所有的巫師。
<ID> 列出<ID>代表玩家所屬門派的玩家。

    who @mudname 則顯示其他聯網泥巴里的玩家。

"HIG"*"NOR" 表示"HIG"發呆"NOR"中，"HIR"#"NOR" 表示"HIR"斷線"NOR"中。

相關指令： finger
"
    );
    return 1;
}
