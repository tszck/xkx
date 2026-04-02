// look.c
inherit F_CLEAN_UP;

#include <room.h>
#include <ansi.h>
#include <combat.h>
#define TIME_TICK1 ((time()-900000000)*60)



int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string getper(object me, object obj);
string tough_level(int power);
string gettof(object me, object obj);
string getdam(object me, object obj);
string *tough_level_desc = ({
        BLU "不堪一擊" NOR,
        BLU "毫不足慮" NOR,
        BLU "不足掛齒" NOR,
        BLU "初學乍練" NOR,
        HIB "初窺門徑" NOR,
        HIB "略知一二" NOR,
	HIB "普普通通" NOR,
	HIB "平平淡淡" NOR,
        HIB "平淡無奇" NOR,
        HIB "粗通皮毛" NOR,
        HIB "半生不熟" NOR,
        HIB "馬馬虎虎" NOR,
	HIB "略有小成" NOR,
        HIB "已有小成" NOR,
        HIB "駕輕就熟" NOR,
        CYN "心領神會" NOR,
        CYN "瞭然於胸" NOR,
	CYN "略有大成" NOR,
	CYN "已有大成" NOR,
        CYN "豁然貫通" NOR,
        CYN "出類拔萃" NOR,
	CYN "無可匹敵" NOR,
	CYN "技冠羣雄" NOR,
        CYN "神乎其技" NOR,
        CYN "出神入化" NOR,
	CYN "傲視羣雄" NOR,
        HIC "登峯造極" NOR,
	HIC "所向披靡" NOR,
        HIC "一代宗師" NOR,
	HIC "神功蓋世" NOR,
        HIC "舉世無雙" NOR,
        HIC "驚世駭俗" NOR,
        HIC "震古鑠今" NOR,
	HIC "深藏不露" NOR,
        HIR "深不可測" NOR,
	HIW "超凡入聖" NOR,
});
string *heavy_level_desc= ({
	"極輕",
	"很輕",
	"不重",
	"不輕",
	"很重",
	"極重"	
});
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;

        if( !arg ) result = look_room(me, environment(me));
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me))))
             {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
             } else result = look_room_item(me, arg);

        return result;
}

int look_room(object me, object env)
{
        int i;
        object *inv;
        mapping exits;
        string str, *dirs;

        if( !env ) {
                write("你的四周灰濛濛地一片，什麼也沒有。\n");
                return 1;
        }
// 天氣顏色
        switch (NATURE_D->outdoor_room_outcolor())
        {
              case "BLK":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + BLK + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "RED":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + RED + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIR":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIR + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "GRN":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + GRN + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIG":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIG + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "YEL":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + YEL + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIY":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIY + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "BLU":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + BLU + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIB":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIB + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "MAG":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + MAG + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIM":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIM + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "CYN":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + CYN + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIC":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIC + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "WHT":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + WHT + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIW":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIW + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              default:
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIG + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
	}
// 天氣到此結束
//        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIY + "%s" + NOR,
//                env->query("short"),
//                wizardp(me)? file_name(env): "",
//                env->query("long"),
//                env->query("outdoors")? NATURE_D->outdoor_room_description():"");

        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
                if ( env->query("outdoors") &&
                    !present("fire", this_player()) &&
                    !wizardp(this_player()) &&
                    ((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "子時") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "醜時") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "寅時") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "亥時") >= 0)))
                        str += "    天色太黑了，你看不清明顯的出路。\n";
                else if( sizeof(dirs)==0 )
                        str += "    這裏沒有任何明顯的出路。\n";
                else if( sizeof(dirs)==1 )
                        str += "    這裏唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
                else
                        str += sprintf("    這裏明顯的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
                                implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
        }
//      str += env->door_description();

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if(inv[i]->query_temp("apply/yinshen")) continue;
                if( !me->visible(inv[i]) ) continue;
                if( userp(inv[i]) )
                        str+="  "+inv[i]->short()+"-"+query_ip_name(inv[i])+"\n";
                else
                        str += "  " + inv[i]->short() + "\n";
        }

        write(str);
        return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;

        write(obj->long());
        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("裏面有：\n  %s\n",
                        implode(inv, "\n  ") ), me);
        }
        return 1;
}
string gettof(object me, object ob)
{
	object weapon;
	string skill_type,parry_type;
	int attack_points;
        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
                parry_type = "parry";
        }
        else
        {
                skill_type = "unarmed";
                parry_type = "unarmed";
        }

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
//        attack_points = ob->query_temp("apply/attack");
	return tough_level((int)(attack_points/100));
}
int look_living(object me, object obj)
{
        int per;
//      int spi;
        int age;
//      int weight;
        string str/*, limb_status*/, pro;
        mixed *inv;
        mapping my_fam, fam;
        int me_shen, obj_shen;
        int equip, wearornot;

        me_shen = (int)me->query("shen");
        obj_shen = (int)obj->query("shen");
//      per = obj->query("per");
        per = obj->query_per();
        age = obj->query("age");

        if( me!=obj )
                message("vision", me->name() + "正盯著你看，不知道打些什麼主意。\n", obj);

        str = obj->long();
        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	if (obj->query_temp("is_riding"))
                str += sprintf("%s正騎在%s上，低頭看着你。\n", pro, obj->query_temp("is_riding"));

        if( (string)obj->query("race")=="人類"
        &&      intp(obj->query("age")) )
        {
                str += sprintf("%s看起來約%s多歲。\n", pro, chinese_number(obj->query("age") / 10 * 10));
                str += sprintf("%s的武功看來", pro);
		str +=gettof(me,obj);
		str +=sprintf("，");
		str +=sprintf("出手似乎");
		str +=getdam(me,obj);
		str +=sprintf("。\n");
        }
        if(age > 70 ) per = per/4;
        if(age > 60 ) per = per/3;
        if(age > 50 ) per = per/2;
        if (living(obj) && obj->query("race")=="野獸" )
        {
                if (!obj->query_temp("owner"))
                   str += pro+"是一隻未被馴服的畜生，眼光裏滿是戒心和敵意。\n";
                else
                   str += pro+"是一隻被"+obj->query_temp("ownername")+"馴服的畜生，一副很溫馴的樣子。\n";
        }
        else
        if(age < 16 ) str +=pro+ "身量不足，形容尚小。\n";
        else
        {
            if ((string) obj->query("gender") == "男性" || (string) obj->query("gender") == "無性")
            {
                if (per >= 30) str +=pro+ "長得宛如玉樹臨風，風流倜儻，顧盼之間，神采飛揚。真正是人中龍鳳！\n";
                if ((per >= 26) && (per < 30))
                    str += pro+"英俊瀟灑，氣宇軒昂，風度翩翩，面目俊朗，貌似潘安。\n";
                if ((per >= 22) && (per < 26))
                    str += pro+"相貌英俊，儀表堂堂。骨格清奇，丰姿非俗。\n";
                if ((per >= 18) && (per < 22))
                    str += pro+"五官端正。\n";
                if ((per >= 15) && (per < 18))
                    str += pro+"相貌平平。沒什麼好看的。\n\n";
                if (per < 15)
                    str += pro+"長得...有點對不住別人。\n";
            }
            else
            {
                if ((string) obj->query("gender") == "女性")
                {
                    if (per >= 30)
                        str += pro+"有傾國傾城之貌，容色麗都，嬌豔絕倫，堪稱人間仙子！\n長髮如雲，肌膚勝雪，風華絕代，不知傾倒了多少英雄豪傑。\n";
                    if ((per >= 28) && (per < 30))
                        str += pro+"清麗絕俗，風姿動人。有沉魚落雁之容，避月羞花之貌！\n俏臉生春，妙目含情，顧盼神飛，輕輕一笑，不覺讓人怦然心動。\n";
                    if ((per >= 26) && (per < 28))
                        str += pro+"膚如凝脂，眉目如畫，風情萬種，楚楚動人。當真是我見猶憐！\n";
                    if ((per >= 24) && (per < 26))
                        str += pro+"容色秀麗，面帶暈紅，眼含秋波。舉手投足之間，確有一番風韻。\n";
// 玉面嬌容花含露，纖足細腰柳帶煙。
                    if ((per >= 21) && (per < 24))
                        str += pro+"氣質高雅，面目姣好，雖算不上絕世佳人，也頗有幾份姿色。\n";
                    if ((per >= 18) && (per < 21))
                        str += pro+"相貌平平，還看得過去。\n";
                    if ((per >= 15) && (per <18))
                        str += pro+"的相貌嘛...馬馬虎虎吧。\n";
                    if (per < 15)
                        str += "咦，"+pro+"長得和無鹽有點相似耶。\n";
                }
            }
        }
        wearornot = 0;
        inv = all_inventory(obj);
        for(equip=0; equip<sizeof(inv); equip++)
        {
                if( inv[equip]->query("equipped") ) wearornot = 1;
        }
        //check about wife and husband
        if((obj->parse_command_id_list())[0]==me->query("couple/couple_id") )
        {
              if( (string)me->query("gender")=="女性" )
              {
                    str += sprintf("%s是你的丈夫。\n", pro);
              }
              else{
                    str += sprintf("%s是你的妻子。\n", pro);
              }
        }
        if (me->query("jiebai"))
        if (strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
        {
              if( obj->query("gender")=="女性" )
              {
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s是你的義姐。\n", pro);
                    else
                        str += sprintf("%s是你的結義妹子。\n", pro);
              }
              else{
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s是你的結義兄長。\n", pro);
                    else
                        str += sprintf("%s是你的義弟。\n", pro);
              }
        }
        if((wearornot == 0 ) && userp(obj) && !wizardp(obj) )
            str += pro+"身上居然什麼都沒穿耶！\n";
        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family"))
        &&      fam["family_name"] == my_fam["family_name"] ) {

                if( fam["generation"]==my_fam["generation"] ) {

                        if( (string)obj->query("gender") == "男性" ||
                                (string)obj->query("gender") == "無性")
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "同門",
                                        my_fam["enter_time"] > fam["enter_time"] ? "師兄": "師弟");
                        else
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "同門",
                                        my_fam["enter_time"] > fam["enter_time"] ? "師姐": "師妹");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "是你的師父。\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "是你的同門長輩。\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += pro + "是你的師伯。\n";
                        else
                                str += pro + "是你的師叔。\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "是你的同門晚輩。\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "是你的弟子。\n";
                        else
                                str += pro + "是你的師侄。\n";
                }
        }

        if( obj->query("max_qi") )
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi")* 100 / (int)obj->query("max_qi")) + "\n";

	if(obj->is_corpse() && obj->query("kantou") == 1) str += sprintf("%s連頭都被割走了。\n", pro);

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s的遺物有：\n%s\n": "%s身上帶著：\n%s\n",
                                pro, implode(inv, "\n") );
        }

        message("vision", str, me);

        if( obj!=me && living(obj)
        && (((me_shen < 0) && (obj_shen > 0)) || ((me_shen > 0) && (obj_shen < 0)))
        && (((me_shen - obj_shen) > ((int)obj->query("neili") * 20))
        || ((obj_shen - me_shen) > ((int)obj->query("neili") * 20))))
        {
                write( obj->name() + "突然轉過頭來瞪你一眼。\n");
                if(obj->query("age") > 15 && me->query("age") > 15)
                   if(!wizardp(obj) && !wizardp(me) && obj->query_temp("guardfor") != me && (obj->parse_command_id_list())[0] != me->query("couple/couple_id"))
                        COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("equipped") )
                str = HIC "  □" NOR + str;
        else if( !flag )
                str = "    " + str;
        else
                return 0;

        return str;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("這裏只有灰濛濛地一片，什麼也沒有。\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));

                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("你要看什麼？\n");
}
string tough_level(int power)
{

	int lvl;
	int rawlvl;
	int grade = 1;
	if(power<0) power=0;
	rawlvl = (int) pow( (float) 1.0 * power, 0.3);
	lvl = to_int(rawlvl/grade);
        if( lvl >= sizeof(tough_level_desc) + 7)
	        lvl = sizeof(tough_level_desc)-1;
	else if (lvl >= sizeof(tough_level_desc) - 1)
		lvl = sizeof(tough_level_desc)-2;
        return tough_level_desc[((int)lvl)];
}
string getdam(object me, object obj)
{

	int level;
	level = obj->query_temp("apply/damage") + obj->query("jiali");
	level = level / 30;
                        if( level >= sizeof(heavy_level_desc) )
                                level = sizeof(heavy_level_desc)-1;
                        return heavy_level_desc[((int)level)];
}

int help (object me)
{
        write(@HELP
指令格式: look [<物品>|<生物>|<方向>]

這個指令讓你查看你所在的環境、某件物品、生物、或是方向。

HELP
);
        return 1;
}
