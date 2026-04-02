// adm/daemons/logind.c
// Modified by Constant Apr 19 2000
// Modified by Constant Jan 2 2001
// Modified by Zeratul Jan 12 2001 存款限制移至updated.c中

inherit F_DBASE;

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <localtime.h>

#define VISITORS "/log/MUDVISITOR"
#define GIFTCARD "/log/GIFTCARD"



int wiz_lock_level = WIZ_LOCK_LEVEL;
// tentop
int mad_lock = 0;
// 浩劫產生的條件變量
int dienpc = 0;
string *banned_name = ({
    "你", "你", "我", "他", "她", "它", "媽", "爸", "　",
    "翔少爺", "方舟子", "草魚", "時空", "丁",
    "木人", "赫連鐵樹", "單正", "韋小寶","火雲",
        "仙子", "風兒", "凡狗", "演若達多", "寒江雪", "【我★愛】",
        "紫志龍"
});

string *wiz_ip = ({
    "127.0.0.1",
    "210.34.9.71",
    "210.34.1.193",
    "localhost",
    "210.34.9.25",
    "210.34.4.159"
});

private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
private void sel_str(string item, object ob, mapping my,int all,int min,int max);
private void sel_int(string item, object ob, mapping my,int all,int min,int max);
private void sel_con(string item, object ob, mapping my,int all,int min,int max);
private init_new_player(object user);
private void get_hometown(string born,object ob );
private void config_gift(object me,mapping my);
private void delete_err_pass(string yn,object ob,object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object make_body(object ob);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
int howmuch_money(object ob);
int howmany_visitor();
int howmany_card();
void set_visitor(int num);
void set_card(int num);
// tentop

void create()
{
    seteuid(getuid());
    set("channel_id", "連線精靈");
}

void logon(object ob)
{
    object *usr;
    int i, inv_wiz_cnt, wiz_cnt, ppl_cnt, login_cnt;
    int iplimit;
    int in_login;
    int user_num;

    if (BAN_D->is_banned(query_ip_name(ob)) == 1) {
        write("對不起，您的地址不受歡迎。\n");
        destruct(ob);
        return;
    }
    cat(WELCOME);
    "/cmds/usr/time"->main();

    usr = users();
    wiz_cnt = 0;
    inv_wiz_cnt = 0;
    ppl_cnt = 0;
    login_cnt = 0;
    iplimit = 0;
    in_login = 0;

    for(i=0; i<sizeof(usr); i++)
    {
        if( query_ip_name(usr[i])==query_ip_name(ob))
            iplimit ++;
        if ( member_array(query_ip_name(ob), wiz_ip) == -1 &&
            !environment(usr[i]))
            in_login ++;
        if( !environment(usr[i]) )
            login_cnt++;
        else if( wizardp(usr[i]) && (usr[i]->query("env/invisibility") || usr[i]->query("no_look_wiz")) )
            inv_wiz_cnt++;
        else if( wizardp(usr[i]) && !usr[i]->query("env/invisibility") )
            wiz_cnt++;
        else ppl_cnt++;
    }

    if (in_login > 10 && !member_array(query_ip_name(ob), wiz_ip))
    {
               write("對不起，俠客行一百現在正忙着呢，請稍後再試。\n");
        destruct(ob);
        return;
    }

    if (BAN_D->is_multi(query_ip_name(ob), iplimit-1))
    {
        write("對不起，您所在的地址無法登錄更多的角色。\n");
        destruct(ob);
        return;
    }
// 計數 Start
    user_num=howmany_visitor();
    write("您是俠客行一百自二千零一年一月十四日以來的第"+HIY+chinese_number(user_num+1)+NOR"位訪問者。\n");
    set_visitor(user_num+1);
    if (iplimit>1)
    write("您所在的地址已有"HIY+chinese_number(iplimit-1)+NOR"位玩家在線上。\n");
/*	if (iplimit>8)
    {
        write("對不起，您所在的地址無法登錄更多的角色。\n");
        destruct(ob);
        return;
    }
*/
// 計數 End
    log_file( "PLAYERNUM", sprintf("At %s: %d %s\n", ctime(time()), ppl_cnt , query_ip_name(ob)) );
    printf( "目前共有 %s 位世外高人、%s 位江湖兒女在線上，以及 %s 位使用者嘗試連線中。\n",
        chinese_number(wiz_cnt),
        chinese_number(ppl_cnt),
        chinese_number(login_cnt+inv_wiz_cnt) );

    write("您的英文名字：");
    input_to( "get_id", ob );
}

void set_visitor(int num)
{
    if (num>0) write_file(VISITORS, sprintf("VISITORS %d", num), 1);
    else write("巫師請注意訪問者數目不對！\n");
    return;
}

void set_card(int num)
{
    if (num>0) write_file(GIFTCARD, sprintf("GIFTCARD %d", num), 1);
    else write("巫師請注意訪問者數目不對！\n");
    return;
}

int howmany_user()
{
    int i,ppl_cnt;
    string *dir , *ppls;
    // mixed info;
    seteuid(getuid());
    ppl_cnt=0;
    dir=get_dir(DATA_DIR+"login/");
    for(i=0; i<sizeof(dir);i++)
    {
        reset_eval_cost();
        ppls=get_dir(DATA_DIR+"login/"+dir[i]+"/");
        ppl_cnt+=sizeof(ppls);
    }
    return ppl_cnt;
}

int howmany_visitor()
{
    int num=0;
    string content, format;
    content=read_file(VISITORS);
    sscanf(content, "%s %d", format, num);
    if(format!="VISITORS") write(format+"\n巫師請注意訪問者數目不對！\n");
    return num;
}

int howmany_card()
{
    int num=0;
    string content, format;
    content=read_file(GIFTCARD);
    sscanf(content, "%s %d", format, num);
    if(format!="GIFTCARD") write(format+"\n巫師請注意訪問者數目不對！\n");
    return num;
}

private void get_id(string arg, object ob)
{
    object ppl, *ob_list;
    int i,j;

    arg = lower_case(arg);
    if( !check_legal_id(arg))
    {
        write("您的英文名字：");
        input_to("get_id", ob);
        return;
    }

#ifdef MAX_USERS
    if( (string)SECURITY_D->get_status(arg)=="(player)" &&
//		sizeof(users()) >= MAX_USERS )
        sizeof(users()) > 1000 )
    {
        ppl = find_body(arg);
// Only allow reconnect an interactive player when MAX_USERS exceeded.
        if( !ppl || !interactive(ppl) )
        {
            write("對不起，"+MUD_NAME+ "的使用者已經太多了，請待會再來。\n");
            destruct(ob);
            return;
        }
    }
#endif

        if( wiz_level(arg) < wiz_lock_level )
    {
        write("對不起，" + MUD_NAME + "目前限制巫師等級 " + WIZ_LOCK_LEVEL + " 以上的人才能連線。\n");
        destruct(ob);
        return;
    }

    if( (string)ob->set("id", arg) != arg )
    {
        write("Failed setting user name.\n");
        destruct(ob);
        return;
    }
/*
    if( arg=="guest" )
    {
        // If guest, let them create the character.
        confirm_id("Yes", ob);
        return;
    } else
*/
    if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 )
    {
        if( ob->restore() )
        {
            write("請輸入密碼：");
            input_to("get_passwd", 1, ob);
            return;
        }
//		write("您的人物儲存擋出了一些問題，請利用 guest 人物通知巫師處理。\n");
        write("您的人物儲存擋出了一些問題，請利用其他帳號通知巫師處理。\n");
        destruct(ob);
        return;
    }
    else
            if(strwidth(arg) > 8)
        {
            write("您的英文名字太長了，請選擇短一點的。\n");
            destruct(ob);
            return;
        }

    ob_list = users();
    j = 0;
    for(i=0;i<sizeof(ob_list);i++)
    {
        if((string)ob_list[i]->query("id")==arg) j++;
    }
    if(j>1)
    {
        write("對不起，有人正在使用該代號註冊，請換一個代號登錄。\n");
        destruct(ob);
        return;
    }

    write("使用 " + (string)ob->query("id") + " 這個名字將會創造一個新的人物，您確定嗎(y/n)？");
    input_to("confirm_id", ob);
}

private void get_passwd(string pass, object ob)
{
    string my_pass;
    object user;
    int i;
    mapping m;
    string *k;

    write("\n");
    my_pass = ob->query("password");
    if( crypt(pass, my_pass) != my_pass )
    {
        write("密碼錯誤！\n");
        ob->set("error_pass/"+ctime(time()),query_ip_name(ob));
        ob->save();
        destruct(ob);
        return;
    }

// Check if we are already playing.
    user = find_body(ob->query("id"));
    if (user)
    {
        if( user->query_temp("netdead") )
        {
            reconnect(ob, user);
            return;
        }
        write("您要將另一個連線中的相同人物趕出去，取而代之嗎？(y/n)");
        input_to("confirm_relogin", ob, user);
        return;
    }

    if (!ob->query("scborn/reset_gift"))
    if( objectp(user = make_body(ob)) )
    {
        if( user->restore() )
        {
            log_file( "USAGE", sprintf("%s (%s) loggined from %s (%s)\n", user->query("name"),user->query("id"),query_ip_name(ob),ctime(time())));
            if (mapp(m = ob->query("error_pass")))
            {
                if ((string)SECURITY_D->get_status(ob->query("id"))=="(player)")
                {
                    delete_err_pass("y",ob,user);
                    return;
                }
                k = keys(m);
                for (i=0;i<sizeof(m);i++)
                    write(k[i]+"\t"+m[k[i]]+"\n");
                write("刪除以上密碼錯誤記錄？[y/n]");
                input_to("delete_err_pass",ob,user);
                return;
            }
            enter_world(ob, user);
            return;
        }
        destruct(user);
    }
    write("請您重新創造這個人物。\n");
    confirm_id("y", ob);
}
private void delete_err_pass(string yn,object ob,object user)
{
    if (yn=="")
    {
        write("刪除以上密碼錯誤記錄？[y/n]");
        input_to("delete_err_pass",ob,user);
        return;
    }
    if(yn[0]=='y' || yn[0]=='Y')
        ob->delete("error_pass");
    enter_world(ob,user);
}

private void confirm_relogin(string yn, object ob, object user)
{
    object old_link;

    if( yn=="" )
    {
        write("您要將另一個連線中的相同人物趕出去，取而代之嗎？(y/n)");
        input_to("confirm_relogin", ob, user);
        return;
    }

    if( yn[0]!='y' && yn[0]!='Y' )
    {
        write("好吧，歡迎下次再來。\n");
        destruct(ob);
        return;
    } else {
        tell_object(user, "有人從別處( " + query_ip_number(ob) + " )連線取代你所控制的人物。\n");
//		log_file( "USAGE", sprintf("%s (%s) replaced by %s (%s)\n", user->query("name"), user->query("id"), query_ip_name(ob), ctime(time()) ) );
        log_file( "LOGIN", sprintf("%-20s replaced by   %15s (%s)\n", user->query("name")+"("+user->query("id")+")",query_ip_name(ob),ctime(time()) ) );
    }

    // Kick out tho old player.
    old_link = user->query_temp("link_ob");
    if( old_link )
    {
        exec(old_link, user);
        destruct(old_link);
    }

    reconnect(ob, user);
}

private void confirm_id(string yn, object ob)
{
    if( yn=="" )
    {
        write("使用這個名字將會創造一個新的人物，您確定嗎(y/n)？");
        input_to("confirm_id", ob);
        return;
    }
    if( yn[0]!='y' && yn[0]!='Y' )
    {
        write("好吧，那麼請重新輸入您的英文名字：");
        input_to("get_id", ob);
        return;
    }
    ob->set_temp("new_char", 1);
    write( @TEXT

請輸入您的高姓大名，由於這個名字代表你的人物，而且以後不能更改，
務必慎重擇名（不雅觀的姓名將被刪除）。另：請不要選擇金庸小說中
已有人物姓名。

TEXT
    );
    write("您的中文名字：");
    input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
    arg = trim(arg);
    if (!check_legal_name(arg))
    {
        write("您的中文名字：");
        input_to("get_name", ob);
        return;
    }
    ob->set("name", arg);
    write("請設定您的密碼：");
    input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
    write("\n");
    if( strwidth(pass)<5 )
    {
        write("密碼的長度至少要五個字元，請重設您的密碼：");
        input_to("new_password", 1, ob);
        return;
    }
    ob->set("password", crypt(pass,0) );
    write("請再輸入一次您的密碼，以確認您沒記錯：");
    input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
    string old_pass;
    write("\n");
    old_pass = ob->query("password");
    if( crypt(pass, old_pass)!=old_pass )
    {
        write("您兩次輸入的密碼並不一樣，請重新設定一次密碼：");
        input_to("new_password", 1, ob);
        return;
    }
    write(@TEXT

請選擇你的人物出生地：

    參天之樹，必有其根，懷山之水，必有其源。
    故鄉，是遊子夢魂縈繞、輾轉反側的地方，是遊子心中最深最沉的牽掛。

    你可以選擇出生在下列城市：

    1〖 北京 〗 〖 開封 〗 〖 南陽 〗 〖 靈州 〗 〖 漠北 〗 〖 西夏 〗
    2〖 長安 〗 〖 洛陽 〗 〖 蘭州 〗 〖 漢中 〗 〖 襄陽 〗 〖 永登 〗
    3〖 揚州 〗 〖 杭州 〗 〖 蘇州 〗 〖 無錫 〗 〖 嘉興 〗 〖 宜興 〗
    4〖 福州 〗 〖 泉州 〗 〖 臺灣 〗 〖 延平 〗 〖 石樑 〗 〖 澎湖 〗
    5〖 大理 〗 〖 衡陽 〗 〖 江陵 〗 〖 嶽陽 〗 〖 佛山 〗 〖 成都 〗

    請輸入數字（1~5）選擇你想出生的地區範圍，具體城市由系統隨機選擇。
TEXT);
    input_to("get_hometown",ob);

}

private void get_hometown(string born,object ob )
{
    mapping my;
    string hometown;
    int j;
    object old;

    j = random(6);
      my = ([]);
      my["area"] = born;
    switch (born)
    {
        case "1" :
            switch (j)
            {
                case 0:hometown = "北京";my["START_ROOM"]="/d/beijing/kedian";break;
                case 1:hometown = "開封";my["START_ROOM"]="/d/kaifeng/daoxiang1";break;
                case 2:hometown = "南陽";my["START_ROOM"]="/d/nanyang/kedian1";break;
                case 3:hometown = "靈州";my["START_ROOM"]="d/lingzhou/chema";break;
                case 4:hometown = "漠北";my["START_ROOM"]="/d/mobei/menggubao1";break;
                default:hometown = "西夏";my["START_ROOM"]="d/lingzhou/chema";break;
            }
            break;

        case "2" :
            switch (j)
            {
                case 0:hometown = "長安";my["START_ROOM"]="/d/changan/kedian";break;
                case 1:hometown = "蘭州";my["START_ROOM"]="/d/lanzhou/kedian";break;
                case 2:hometown = "漢中";my["START_ROOM"]="/d/hanzhong/kedian1";break;
                case 3:hometown = "洛陽";my["START_ROOM"]="/d/luoyang/luoshenmiao";break;
                case 4:hometown = "襄陽";my["START_ROOM"]="/d/xiangyang/kedian";break;
                default:hometown = "永登";my["START_ROOM"]="/d/yongdeng/kedian";break;
            }
            break;
        case "3" :
            switch (j)
            {
                case 0:hometown = "揚州";my["START_ROOM"]="/d/city/kedian";break;
                case 1:hometown = "杭州";my["START_ROOM"]="/d/hangzhou/kedian";break;
                case 2:hometown = "蘇州";my["START_ROOM"]="/d/suzhou/kedian";break;
                case 3:hometown = "無錫";my["START_ROOM"]="/d/wuxi/kedian";break;
                case 4:hometown = "嘉興";my["START_ROOM"]="/d/jiaxing/yanyu";break;
                default:hometown = "宜興";my["START_ROOM"]="/d/yixing/nanxun";break;
            }
            break;
        case "4" :
            switch (j)
            {
                case 0:hometown = "福州";my["START_ROOM"]="/d/fuzhou/rongcheng";break;
                case 1:hometown = "泉州";my["START_ROOM"]="/d/quanzhou/kedian";break;
                case 2:hometown = "臺灣";my["START_ROOM"]="/d/taiwan/anping";break;
                case 3:hometown = "延平";my["START_ROOM"]="/d/yanping/road3";break;
                case 4:hometown = "石樑";my["START_ROOM"]="/d/shiliang/gate";break;
                default:hometown = "澎湖";my["START_ROOM"]="/d/taiwan/penghu";break;
            }
            break;
        default  :
            switch (j)
            {
                case 0:hometown = "衡陽";my["START_ROOM"]="/d/henshan/chaguan";break;
                case 1:hometown = "江陵";my["START_ROOM"]="/d/jiangling/majiu";break;
                case 2:hometown = "嶽陽";my["START_ROOM"]="/d/yueyang/yueyanglou1";break;
                case 3:hometown = "佛山";my["START_ROOM"]="/d/foshan/yingxionglou";break;
                case 4:hometown = "大理";my["START_ROOM"]="/d/dali/baiyiminju";break;
                default:hometown = "成都";my["START_ROOM"]="/d/chengdu/kedian";break;
            }
            break;
    }
      write("\n您的出生地是："+hometown+"\n");
      my["hometown"]= hometown;
          write(@TEXT
****************************************************************************
**      一個人物的天賦對於他或她所修習的武藝息息相關。俠客行中的人物大    **
**  多具有以下四項顯性天賦：                                              **
**                                                                        **
**  膂力：影響攻擊能力及負荷量的大小。                                    **
**  悟性：影響學習武功祕籍的速度及理解師傅的能力。                        **
**  根骨：影響體力恢復的速度及升級後所增加的體力。                        **
**  身法：影響防禦及躲避的能力。                                          **
**                                                                        **
**      每個人物另外還有六項起作用的隱性屬性：                            **
**                                                                        **
**  耐力：影響到打鬥。耐力高的，在打鬥中能更快地恢復元氣。                **
**  靈性：影響技能學習。靈性高的，更容易多學些功夫。                      **
**  膽識：影響攻擊成功率。膽識高的，傾向於進攻。                          **
**  定力：影響防禦成功率。定力低的，容易被對手找到破綻反擊。              **
**  福緣：影響到在遊戲裏的機遇。總體來說，越高越好。但不絕對如此。        **
**  容貌：容貌好的人，不容易引起敵意。對定力低的敵手，有震懾作用。        **
**                                                                        **
****************************************************************************
TEXT);
  if (ob->query("scborn/reset_gift"))
  {
      old = NPC_D->create_player(ob->query("id"));
      write("你前世的天賦爲：\n\n");
      write("臂力：[ "+old->query("str")+" ]\t");
      write("悟性：[ "+old->query("int")+" ]\n");
      write("根骨：[ "+old->query("con")+" ]\t");
      write("身法：[ "+old->query("dex")+" ]\n");
      write("耐力：[ "+old->query("sta")+" ]\t");
      write("容貌：[ "+old->query("per")+" ]\n");
      write("靈性：[ "+old->query("spi")+" ]\t");
      write("福緣：[ "+old->query("kar")+" ]\n");
      write("膽識：[ "+old->query("cor")+" ]\t");
      write("定力：[ "+old->query("cps")+" ]\n");
      write("\n");
      destruct(old);
      write("你要繼承前世的屬性嗎？(Y/N)");
      input_to("confirm_gift",ob,my);
      return;
  }
  config_gift(ob,my);
}

private void confirm_gift(string arg,object ob,mapping my)
{
    object old;
    string chartype;

    arg = lower_case(arg);
    if (arg == "y" || arg == "Y")
    {
        write("\n你繼承前世的先天屬性。\n");
      old = NPC_D->create_player(ob->query("id"));
      my["str"]=old->query("str")+2;
      my["int"]=old->query("int");
      my["con"]=old->query("con")+2;
      my["dex"]=old->query("dex")+2;
      my["sta"]=old->query("sta")+2;
      my["per"]=old->query("per")+2;
      my["spi"]=old->query("spi")+2;
      my["kar"]=old->query("kar")+2;
      my["cor"]=old->query("cor")+2;
      my["cps"]=old->query("cps")+2;
      chartype = old->query("character");
      destruct(old);
      write("您的電子郵件地址：");
        input_to("get_email", ob, my,chartype);
    }
    else if (arg == "n" || arg == "N")
    {
        write("你重新自己的先天屬性。\n");
        config_gift(ob,my);
    }
    else
      write("你要繼承前世的屬性嗎？(Y/N)");
      input_to("confirm_gift",ob,my);
}

private void config_gift(object ob,mapping my)
{
    int all,min,max;

    all = 80+10*ob->query("scborn/times");
    if (ob->query("scborn/times")) all += 10;
    max = 30+5*ob->query("scborn/times");
    min = (all-max-max)/2;
//	min = 10+5*ob->query("scborn/times");
    printf("你的天賦總點數爲"+all+"，您請輸入您的膂力點數("+min+"到"+max+")：");
    input_to("sel_str", ob, my, all, min, max);
}

private void sel_str(string qty1, object ob, mapping my, int all, int min, int max)
{
    int qty;
    qty = atoi(qty1);
    if (qty < min)
    {
        write(HIR"您選擇的膂力數值不能小於"+min+"：\n"NOR);
        printf("你的天賦總點數爲"+all+"，您請輸入您的膂力點數("+min+" 到 "+max+")：");
        input_to("sel_str", ob, my, all, min, max);
    }
    else
    if (qty > max)
    {
        write(HIR"您選擇的膂力數值不能大於"+max+"：\n"NOR);
        printf("你的天賦總點數爲"+all+"，您請輸入您的膂力點數("+min+" 到 "+max+")：");
        input_to("sel_str", ob, my, all, min, max);
    }
    else
    {
        my["str"] = qty;
        printf("你的天賦點數尚餘%d點，您請輸入您的悟性點數("+min+" 到 "+max+")：", all-my["str"]);
        input_to("sel_int", ob, my, all, min, max);
        return;
    }
}

private void sel_int(string qty1, object ob, mapping my, int all, int min, int max)
{
    int qty;
    qty = atoi(qty1);
    if (qty < min)
    {
        write(HIR"您選擇的悟性數值不能小於"+min+"：\n"NOR);
        printf("你的天賦點數尚餘%d點，您請輸入您的悟性點數("+min+" 到 "+max+")：", 80-my["str"]);
        input_to("sel_int", ob, my, all, min, max);
    }
    else
    if (qty > max)
    {
        write(HIR"您選擇的悟性數值不能大於"+max+"：\n"NOR);
        printf("你的天賦點數尚餘%d點，您請輸入您的悟性點數("+min+" 到 "+max+")：", 80-my["str"]);
        input_to("sel_int", ob, my, all, min, max);
    }
    else
    {
        my["int"] = qty;
        printf("你的天賦點數尚餘%d點，您請輸入您的根骨點數(%d 到 %d)：",
    all-my["str"]-my["int"],
        ((all-my["str"]-my["int"])<(max+min)?min:all-my["str"]-my["int"]-max),
        (all-my["str"]-my["int"])>(max+min)?max:all-my["str"]-my["int"]-min);
//		  80-my["str"]-my["int"],
//		  (80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30,
//		  (80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
        input_to("sel_con", ob, my, all, min, max);
        return;
    }
}

private void sel_con(string qty1, object ob, mapping my, int all, int min, int max)
{
    int qty;
    qty = atoi(qty1);
    if(qty<min)
    {
        write(HIR"您選擇的根骨數值不能小於"+min+"：\n"NOR);
        printf("你的天賦點數尚餘%d點，您請輸入您的根骨點數(%d 到 %d)：",
        all-my["str"]-my["int"],
        (all-my["str"]-my["int"])<(max+min)?min:all-my["str"]-my["int"]-max,
        (all-my["str"]-my["int"])>(max+min)?max:all-my["str"]-my["int"]-min);
//		80-my["str"]-my["int"],
//(80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30,
//(80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
        input_to("sel_con", ob, my,all,min,max);
    }
    else
    if(qty>max)
    {
        write(HIR"您選擇的根骨數值不能大於"+max+"：\n"NOR);
        printf("你的天賦點數尚餘%d點，您請輸入您的根骨點數(%d 到 %d)：",
        all-my["str"]-my["int"],
        (all-my["str"]-my["int"])<(max+min)?min:all-my["str"]-my["int"]-max,
        (all-my["str"]-my["int"])>(max+min)?max:all-my["str"]-my["int"]-min);
//		80-my["str"]-my["int"],
//		(80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30,
//		(80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
        input_to("sel_con", ob, my,all,min,max);
    }
    else
    if (all-my["str"]-my["int"]>(max+min))
    {
        if(qty<all-my["str"]-my["int"]-max)
        {
            write(HIR"您選擇的根骨數值不在允許範圍內。\n"NOR);
//			printf("你的天賦點數尚餘%d點，您請輸入您的根骨點數(%d 到 %d)：", 80-my["str"]-my["int"], (80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30, (80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
        printf("你的天賦點數尚餘%d點，您請輸入您的根骨點數(%d 到 %d)：",
        all-my["str"]-my["int"],
        (all-my["str"]-my["int"])<(max+min)?min:all-my["str"]-my["int"]-max,
        (all-my["str"]-my["int"])>(max+min)?max:all-my["str"]-my["int"]-min);
            input_to("sel_con", ob, my,all,min,max);
        }
        else
        {
            my["con"] = qty;
            my["dex"] = all-my["str"]-my["int"]-my["con"];
            printf("\n膂力[%d]， 悟性[%d]， 根骨[%d]， 身法[%d]\n", my["str"], my["int"], my["con"], my["dex"]);
            write("您同意這一組天賦嗎？");
            input_to("get_gift", ob, my);
            return;
        }
    }
    else
    {
        if(qty>all-my["str"]-my["int"]-min)
        {
            write(HIR"您選擇的根骨數值不在允許範圍內。\n"NOR);
//		printf("你的天賦點數尚餘%d點，您請輸入您的根骨點數(%d 到 %d)：", 80-my["str"]-my["int"], (80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30, (80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
        printf("你的天賦點數尚餘%d點，您請輸入您的根骨點數(%d 到 %d)：",
        all-my["str"]-my["int"],
        (all-my["str"]-my["int"])<(max+min)?min:all-my["str"]-my["int"]-max,
        (all-my["str"]-my["int"])>(max+min)?max:all-my["str"]-my["int"]-min);
            input_to("sel_con", ob, my,all,min,max);
        }
        else
        {
            my["con"] = qty;
            my["dex"] = all-my["str"]-my["int"]-my["con"];
            printf("\n膂力[%d]， 悟性[%d]， 根骨[%d]， 身法[%d]\n", my["str"], my["int"], my["con"], my["dex"]);
            write("您同意這一組天賦嗎？");
            input_to("get_gift", ob, my,all,min,max);
            return;
        }
    }
}

private void get_gift(string yn, object ob, mapping my,int all,int min,int max)
{
    if (yn[0] != 'y' && yn[0] != 'Y')
    {
        printf("你的天賦總點數爲"+all+"，您請輸入您的膂力點數("+min+" 到 "+max+")：");
        input_to("sel_str", ob, my,all,min,max);
    }
    if (yn[0] == 'y' || yn[0] == 'Y')
    {
    write(@TEXT

請選擇你的人物性格屬性：

    人生在世，有各種性格和抱負。性格屬性的選擇，或多或少影響了你今後
的發展和未來。但每個性格屬性都不是絕對的，如果你拿不定注意，就選普通
吧。
    你可以選擇下列性格屬性：

    1、冒險：膽識相對高些，不過定力就比較低了。
    2、謹慎：定力相對高些，不過膽識就比較低了。
    3、可人：容貌比較好些，別的不會太好，但也絕不太差。
    4、睿智：靈性高些，能學到比較多的功夫。別的雖然一般，卻也都過得去。
    5、堅韌：耐力高些，但是你選的根骨不宜太低。
    0、普通：什麼都不考慮，也許有機會選到兼具上面若干項的好天賦呢。
TEXT);
        input_to("get_char", ob, my);
    }
}

private void get_char(string chartype, object ob, mapping my)
{
// 福緣
    my["kar"] = 10 + random(21)+5*ob->query("scborn/times");
// 膽識、定力、容貌、靈性、耐力
    switch (chartype)
    {
        case "1" :
            my["cor"] = 20 + random(11)+3*ob->query("scborn/times");
            my["cps"] = 10 + random(11)+3*ob->query("scborn/times");
            my["per"] = 15 + random(11)+3*ob->query("scborn/times");
            my["spi"] = 15 + random(11)+3*ob->query("scborn/times");
            my["sta"] = 15 + random(11)+3*ob->query("scborn/times");
            write("您選擇了冒險的性格。\n");
            break;
        case "2" :
            my["cor"] = 10 + random(11)+3*ob->query("scborn/times");
            my["cps"] = 20 + random(11)+3*ob->query("scborn/times");
            my["per"] = 15 + random(11)+3*ob->query("scborn/times");
            my["spi"] = 15 + random(11)+3*ob->query("scborn/times");
            my["sta"] = 15 + random(11)+3*ob->query("scborn/times");
            write("您選擇了謹慎的性格。\n");
            break;
        case "3" :
            my["cor"] = 13 + random(15)+3*ob->query("scborn/times");
            my["cps"] = 13 + random(15)+3*ob->query("scborn/times");
            my["per"] = 20 + random(11)+3*ob->query("scborn/times");
            my["spi"] = 13 + random(15)+3*ob->query("scborn/times");
            my["sta"] = 13 + random(15)+3*ob->query("scborn/times");
            write("您選擇了可人的性格。\n");
            break;
        case "4" :
            my["cor"] = 13 + random(15)+3*ob->query("scborn/times");
            my["cps"] = 13 + random(15)+3*ob->query("scborn/times");
            my["per"] = 13 + random(15)+3*ob->query("scborn/times");
            my["spi"] = 20 + random(11)+3*ob->query("scborn/times");
            my["sta"] = 13 + random(15)+3*ob->query("scborn/times");
            write("您選擇了睿智的性格。\n");
            break;
        case "5" :
            my["cor"] = 13 + random(15)+3*ob->query("scborn/times");
            my["cps"] = 13 + random(15)+3*ob->query("scborn/times");
            my["per"] = 13 + random(15)+3*ob->query("scborn/times");
            my["spi"] = 13 + random(15)+3*ob->query("scborn/times");
            my["sta"] = 20 + random(11)+3*ob->query("scborn/times");
            write("您選擇了堅韌的性格。\n");
            break;
        default  :
            my["cor"] = 10 + random(21)+3*ob->query("scborn/times");
            my["cps"] = 10 + random(21)+3*ob->query("scborn/times");
            my["per"] = 10 + random(21)+3*ob->query("scborn/times");
            my["spi"] = 10 + random(21)+3*ob->query("scborn/times");
            my["sta"] = 10 + random(21)+3*ob->query("scborn/times");
            write("您不選擇特定的性格。\n");
            break;
    }
  write("\n您的電子郵件地址：");
    input_to("get_email", ob, my,chartype);
}

private void get_email(string email, object ob, mapping my,string chartype)
{
    object user;

    write("\n");
    if (email == "" || strsrch(email, "@") == -1) {
        write("電子郵件地址需要是 id@address 的格式。\n");
        write("您的電子郵件地址：");
        input_to("get_email", ob, my);
        return;
    }
    ob->set("email", email);
    ob->set("registered", 1);

    // If you want do race stuff,ask player to choose one here, then you can
    // set the user's body after the question is answered. The following are
    // options for player's body, so we clone a body here.
    ob->set("body", USER_OB);
    if( !objectp(user = make_body(ob)) ) return;
    if (ob->query("scborn/times")==6)
    {
        my["str"]=60;
        my["dex"]=60;
        my["con"]=60;
        my["int"]=60;
        my["kar"]=60;
        my["cor"]=60;
        my["cps"]=60;
        my["per"]=60;
        my["spi"]=60;
        my["sta"]=60;
    }
    user->set("str", my["str"]);
    user->set("dex", my["dex"]);
    user->set("con", my["con"]);
    user->set("int", my["int"]);
    user->set("kar", my["kar"]);
    user->set("cor", my["cor"]);
    user->set("cps", my["cps"]);
    user->set("per", my["per"]);
    user->set("spi", my["spi"]);
    user->set("sta", my["sta"]);
    user->set("START_ROOM",my["START_ROOM"]);
//save in data
//save in user ob and login ob
    user->set("base",my);
    user->set("scborn/times",ob->query("scborn/times"));
    ob->set("base",my);
/////////
    user->set("character", chartype);
    user->set("born/hometown",my["hometown"]);
    user->set("born/area",my["area"]);
    ob->set("registered", 1);
    user->set("registered", 1);

    write("您要扮演男性(m)的角色或女性(f)的角色？");
    input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
    object res;
    string err;

    write("\n");
    if( gender=="" )
    {
        write("您要扮演男性(m)的角色或女性(f)的角色？");
        input_to("get_gender", ob, user);
        return;
    }

    if( gender[0]=='m' || gender[0]=='M' )
        user->set("gender", "男性");
    else if( gender[0]=='f' || gender[0]=='F' )
        user->set("gender", "女性" );
    else {
        write("對不起，您只能選擇男性(m)或女性(f)的角色：");
        input_to("get_gender", ob, user);
        return;
    }

    log_file( "Newuser", sprintf("%s (%s) was created from %s (%s) with (%d %d %d %d)\n", user->query("name"),user->query("id"),query_ip_name(ob),ctime(time()),user->query("str"),user->query("int"),user->query("con"),user->query("dex")));
    ob->set("created_on",ctime(time()));
     ob->set("created_from",query_ip_name(ob));
    init_new_player(user);
    if (ob->query("scborn/reset_gift"))
    {
        err = catch(res = SCBORN_D->check_user(user,ob));	//讀取保存的東西等
    if (stringp(err))
      CHANNEL_D->do_channel( this_object(), "sys","SCBORN_D CATCH ERROR="+err );
    if (!err && objectp(res)) user = res;
        ob->delete("scborn/reset_gift");
        user->set("scborn/times",ob->query("scborn/times"));
    }
    enter_world(ob, user);
    write("\n");
}

object make_body(object ob)
{
    string err;
    object user;
    // int n;

    user = new(ob->query("body"));
    if(!user) {
        write("現在可能有人正在修改使用者物件的程式，無法進行復制。\n");
        write(err+"\n");
        return 0;
    }
    seteuid(ob->query("id"));
    export_uid(user);
    export_uid(ob);
    seteuid(getuid());
    user->set("id", ob->query("id"));
    user->set_name( ob->query("name"), ({ ob->query("id")}) );
    return user;
}

private init_new_player(object user)
{
    user->set("title", "普通百姓");
    user->set("birthday", time() );
    user->set("potential", 99);
  user->set("jing",100);
  user->set("qi",100);
  user->set("tili",100);
    user->set("food", (user->query("str")+10)*10);
    user->set("water", (user->query("str")+10)*10);

    user->set("channels", ({ "chat", "rumor", "party", "xkx", "sing" , "es" , "snow" }) );
}


varargs void enter_world(object ob, object user, int silent)
{
    object cloth, shoe, mailbox, gift, login_ob;
    string startroom;
    string baseroom;
    mixed *ltime;
    int i, cardnum, is_holiday = 0;

    // 節日映射數組，請按照格式添加新節日。
    // Added by Constant Jan 2 2001.
    mapping *holidays = ({
        ([
            24          : 12,
            25          : 12,
            "cardfile"  : "/clone/misc/cards/card_cs",
        ]),
        ([
            31          : 12,
             1          : 1,
            "cardfile"  : "/clone/misc/cards/card_ny",
        ]),
        ([
            11          : 2,
            12          : 2,
            13          : 2,
            14          : 2,
            "cardfile"  : "/clone/misc/cards/card_ft",
        ]),
    });

    user->set_temp("link_ob", ob);
// 登錄時記錄經驗和潛能, 以及登錄時間, 爲離線信息預留
    user->set_temp("nowexp", user->query("combat_exp"));
    user->set_temp("nowpot", user->query("potential"));
    user->set_temp("nowtime", time());
    user->set_name(user->query("name"),({user->query("id")}));
    ob->set_temp("body_ob", user);
    ob->set_temp("new_char", user);
    user->set("registered", ob->query("registered"));
    exec(user, ob);

    write("\n目前權限：" + wizhood(user) + "\n");
    user->setup();
    if (!user->query("food") && !user->query("water") &&
        ob->query("age") == 14)
    {
        user->set("food", user->max_food_capacity());
        user->set("water", user->max_water_capacity());
    }

    // In case of new player, we save them here right aftre setup
    // compeleted.
    user->save();
    ob->save();
    // Use condition to auto save user file
    user->apply_condition("autosave", 1);

    // 根據時間判斷是否爲節日，並贈送玩家禮品。
    // Added by Constant Jan 2 2001
    ltime = localtime(time());

    for (i = 0; i < sizeof(holidays); i++)
    {
        if (holidays[i][ltime[LT_MDAY]] == ltime[LT_MON]+1)
        {
            if (!user->query("holiday_cards") &&
                user->query("mud_age") > 86400)
            {
                cardnum = howmany_card();
                set_card(cardnum + 1);
                gift = new(holidays[i]["cardfile"]);
                gift->move(user);
                user->set("holiday_cards", cardnum);
            }
            is_holiday = 1;
            break;
        }
    }

    // 若不是節日，則刪除玩家身上屬性，使下一節日能收到贈品。
    // Added by Constant Jan 2 2001
    if (!is_holiday && user->query("holiday_cards"))
        user->delete("holiday_cards");

    if (wizhood(user) == "(player)")
    {
        if (user->query("class")=="bonze")
        {
            if (user->query("gender")=="女性")
            {
                cloth = new("/clone/cloth/ni-cloth");
                shoe = new("/clone/cloth/ni-shoe");
            }
            else
            {
                cloth = new("/clone/cloth/seng-cloth");
                shoe = new("/clone/cloth/seng-shoe");
            }
        }
        else
        {
            if (user->query("class")=="taoist")
            {
                if ( user->query("gender")=="女性")
                {
                    cloth = new("/clone/cloth/daogu-cloth");
                    shoe = new("/clone/cloth/dao-shoe");
                }
                else
                {
                    cloth = new("/clone/cloth/dao-cloth");
                    shoe = new("/clone/cloth/dao-shoe");
                }
            }
            else
            {
                if ( user->query("gender")=="女性")
                {
                    cloth =new("/clone/cloth/female-cloth");
                    shoe = new("/clone/cloth/female-shoe");
                }
                else
                {
                    cloth = new("/clone/cloth/male-cloth");
                    shoe = new("/clone/cloth/male-shoe");
                }
            }
        }
    }
    else
    {
        if ( !user->query("no_look_wiz") )
        {
            cloth = new("/clone/cloth/wiz-cloth.c");
            shoe = new("/clone/cloth/wiz-shoe.c");
        }
        else
        {
            cloth = new("/clone/cloth/male-cloth");
            shoe = new("/clone/cloth/male-shoe");
        }
    }
    cloth->move(user);
    cloth->wear();
    shoe->move(user);
    shoe->wear();

    if( !silent )
    {
        baseroom = START_ROOM;
        if (stringp(user->query("START_ROOM")))
        baseroom=user->query("START_ROOM");
        if (ob->query("registered") == 0) cat(UNREG_MOTD);
        else cat(MOTD);
        if( user->is_ghost() ) startroom = DEATH_ROOM;
        else if( !stringp(startroom = user->query("startroom")) )
            startroom = baseroom;

        if( !catch(load_object(startroom)) ) user->move(startroom);
        else
        {
            user->move(START_ROOM);
            startroom = START_ROOM;
            user->set("startroom", START_ROOM);
        }
        if (!user->query("env/invisibility"))
        tell_room(startroom, user->query("name") + "連線進入這個世界。\n", ({user}));
    }
    login_ob=new(LOGIN_OB);
    login_ob->set("id",user->query("id"));
    login_ob->restore();
    write("\n你上次光臨俠客行一百是 " + HIG +ctime(login_ob->query("last_on"))+ NOR + " 從 " + HIR +login_ob->query("last_from") + NOR + " 連接的。\n\n");
    destruct(login_ob);

    CHANNEL_D->do_channel( this_object(), "sys",
        sprintf("%s(%s)由%s連線進入。共清除 " + reclaim_objects() + " 個變數。\n", user->name(),user->query("id"), query_ip_name(user)) );
    UPDATE_D->check_user(user);
    mailbox = new("/clone/misc/mailbox");
    mailbox->move(user);
//  user->start_call_out( (: call_other,"/cmds/usr/news","check_me",user :),5);
}

varargs void reconnect(object ob, object user, int silent)
{
    user->set_temp("link_ob", ob);
    ob->set_temp("new_char", user);
    ob->set_temp("body_ob", user);
    exec(user, ob);

    user->reconnect();
    if( !silent ) {
        if (!wizardp(user) || !user->query("env/invisibility"))
        tell_room(environment(user), user->query("name") + "重新連線回到這個世界。\n",
        ({user}));
    }
    CHANNEL_D->do_channel( this_object(), "sys",
        sprintf("%s由%s重新連線進入。", user->query("name"), query_ip_name(user)) );
    UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
    int i;

    i = strwidth(id);

    if( (strwidth(id) < 3) || (strwidth(id) > 8 ) ) {
        write("對不起，你的英文名字必須是 3 到 8 個英文字母。\n");
        return 0;
    }
    while(i--)
        if( id[i]<'a' || id[i]>'z' ) {
            write("對不起，你的英文名字只能用英文字母。\n");
            return 0;
        }

    return 1;
}

int check_legal_name(string name)
{
    if (!is_chinese(name))
    {
        write("對不起，請您用「中文」取名字。\n");
        return 0;
    }

    if ((strwidth(name) < 4) || (strwidth(name) > 10))
    {
        write("對不起，你的中文名字必須是 2 到 5 箇中文字。\n");
        return 0;
    }

    if ((strsrch(name, "　") >= 0) ||
        (strsrch(name, "爸") >= 0))
    {
        write("對不起，你的中文名字不能用引起誤會的單字。\n");
        return 0;
    }
    if (member_array(name, banned_name) != -1)
    {
        write("對不起，這種名字會造成其他人的困擾。\n");
        return 0;
    }

    return 1;
}

object find_body(string name)
{
    object ob, *body;

    if( objectp(ob = find_player(name)) )
        return ob;
    body = children(USER_OB);
    for(int i=0; i<sizeof(body); i++)
        if( clonep(body[i])
        &&	getuid(body[i]) == name ) return body[i];

    return 0;
}

int set_wizlock(int level)
{
    if( wiz_level(this_player(1)) <= level )
        return 0;
    if( geteuid(previous_object()) != ROOT_UID )
        return 0;
    wiz_lock_level = level;
    return 1;
}
// add for ten top.
int set_madlock(int setmark)
{
       // if( wiz_level(this_player(1)) < wiz_level("(arch)") )
      // 	return 0;
    if( setmark == 1 ) mad_lock = 1;
    else mad_lock = 0;
    return 1;
}

int get_madlock()
{
    return mad_lock;
}
int howmuch_money(object ob)
{
    int total;
    int total2;
    object gold, silver, coin;

    total = 0;
    total2 = 0;

    gold = present("gold_money",ob);
    silver = present("silver_money",ob);
    coin = present("coin_money",ob);

    if( gold ) total += gold->value();
    if( silver ) total += silver->value();
    if( coin ) total += coin->value();

    total2 = (int)ob->query("balance");
    if (!total2 || total2 < 0) {
        ob->set("balance", 0);
    }
    total=total+total2;
    return total;
}

// 增加浩劫判斷條件變量的讀取和設置
void add_dienpc()
{
    dienpc++;
}
void set_dienpc(int i)
{
    if (i == -1)
    {
            mad_lock = 1;
        dienpc = 0;
        return;
    }
    dienpc = i;
}
int get_dienpc()
{
    return dienpc;
}
