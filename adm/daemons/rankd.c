// rankd.c
// 1996-02-15 dts ranking related to "shen"

#include <ansi.h>

string query_rank(object ob)
{
        mapping fam;

        int shen;
        int budd;
        int age;

        if( ob->is_ghost() )
                return HIB "【 鬼  魂 】" NOR;

        shen = ob->query("shen");
        age = ob->query("age");
        if ( (fam = ob->query("family")) &&
                (fam["family_name"] == "少林派" ||
                fam["family_name"] == "南少林派" ||
                fam["family_name"] == "峨嵋派" ||
                fam["family_name"] == "天龍寺" ||
                fam["family_name"] == "雪山派" ||
                fam["family_name"] == "恆山派"))
                budd = ob->query_skill("buddhism",1);

        switch(ob->query("gender")) {
        case "女性":
                switch(wizhood(ob)) {
                case "(admin)"     : return HIM "【 天  後 】" NOR;
                case "(arch)"      : return HIY "【 仙  妃 】" NOR;
                case "(wizard)"    : return HIG "【 神  女 】" NOR;
                case "(apprentice)": return HIC "【 仙  女 】" NOR;
                case "(immortal)"  : return HIC "【 女仙童 】" NOR;
                default:
                        if (((int)ob->query("betrayer") > 0) &&
                            (!(ob->query("family"))))     return "【 女隱士 】";
                        if (((int)ob->query("PKS") > (int)ob->query("MKS")) &&
                            ((int)ob->query("PKS") > 10)) return "【女殺人魔】";
                        if ((int)ob->query("thief")> 10 ) return "【 女慣竊 】";
                        if (shen >= 100000)       return HIC "【曠世女俠】" NOR;
/*
                        else if (shen >= 10000)   return HIC "【 大女俠 】" NOR;
                        else if (shen >= 1000)    return HIC "【 女  俠 】" NOR;
                        else if (shen >= 100)     return HIC "【 女少俠 】" NOR;
*/
                        else if (shen <=-100000)  return HIC "【 女魔王 】" NOR;
/*
                        else if (shen <= -10000)  return HIC "【 大女魔 】" NOR;
                        else if (shen <= -1000)   return HIC "【 女  魔 】" NOR;
                        else if (shen <= -100)    return HIC "【 女少魔 】" NOR;
*/
                        else
                        switch(ob->query("class")) {
                        case "bonze":
                             if (budd >= 150)     return HIW "【 神  尼 】" NOR;
                             else if (budd >=120) return HIY "【 聖  尼 】" NOR;
                             else if (budd >= 90) return HIY "【 德  尼 】" NOR;
                             else if (budd >= 60) return HIC "【 賢  尼 】" NOR;
                             else if (budd >= 30) return HIG "【 師  太 】" NOR;
                             else if (age  <= 16) return "【 小尼姑 】";
                             else                 return "【 尼  姑 】";
                        case "taoist":            /*正一派*/
                        case "quanzhen":          /*全真派*/
                             if (age <= 16)       return "【 小道姑 】";
                             else if (age <= 30)  return "【 道  姑 】";
                             else                 return "【 玄  女 】";
                        case "scholar":
                             if (age <= 16)       return "【 女學童 】";
                             else if (age <= 30)  return "【 才  女 】";
                             else                 return "【 女學士 】";
                        case "bandit":            return "【 女飛賊 】";
                        case "dancer":            return "【 舞  者 】";
                        case "legend":            return "【 俠  女 】";
                        case "traveller" :        return "【 浪  女 】";
                        case "ninemoon":          return "【 邪  女 】";
                        case "officer":           /* 官差 */
                             budd = (int)ob->query("officerlvl");
                             if (budd == 9)       return HIR"【 女神捕 】" NOR;
                             else if (budd == 8)  return YEL"【一等侍衛】" NOR;
                             else if (budd == 7)  return YEL"【二等侍衛】" NOR;
                             else if (budd == 6)  return YEL"【三等侍衛】" NOR;
                             else if (budd == 5)  return HIG"【女總捕頭】" NOR;
                             else if (budd == 4)  return HIG"【副總捕頭】" NOR;
                             else if (budd == 3)  return HIG"【 女捕頭 】" NOR;
                             else if (budd == 2)  return HIG"【 女捕快 】" NOR;
                             else if (budd == 1)  return HIG"【實習捕快】" NOR;
                             else return "【 女官差 】";
                        case "fighter":           return "【 女武者 】";
                        case "swordsman":         return "【 女劍士 】";
                        case "alchemist":         return "【 女方士 】";
                        case "shaman":            return "【 女巫醫 】";
                        case "lama":              return "【 藏  尼 】";
                        case "generals":          return "【 女  將 】";
                        case "guard":             return "【 女衛士 】";
                        case "minion":            return "【 女家臣 】";
                        case "prostitute":        return "【 妓  女 】";
                        case "beggar":
                             if (shen > 1000)     return "【 女俠丐 】";
                             else if (shen<-1000) return "【 女惡丐 】";
                             else                 return "【 女叫化 】";
                        default:
                                if (age <= 16)    return "【 少  女 】";
                                else              return "【 民  婦 】";
                        }
                }
        default:
                switch(wizhood(ob)) {
                case "(admin)":      if (!ob->query("no_look_wiz")) return HIM "【 天  帝 】" NOR;
                case "(arch)":       if (!ob->query("no_look_wiz")) return HIY "【 天  王 】" NOR;
                case "(wizard)":     if (!ob->query("no_look_wiz")) return HIG "【 神  仙 】" NOR;
                case "(apprentice)": if (!ob->query("no_look_wiz")) return HIC "【 半  仙 】" NOR;
                case "(immortal)":   if (!ob->query("no_look_wiz")) return HIC "【 仙  童 】" NOR;
                default:
                        if (((int)ob->query("betrayer") > 0) &&
                            (!(ob->query("family"))))     return "【 隱  士 】";
                        if (((int)ob->query("PKS") > (int)ob->query("MKS")) &&
                            ((int)ob->query("PKS") > 10)) return "【 殺人魔 】";
                        if ((int)ob->query("thief")> 10 ) return "【 慣  竊 】";
                        if (shen >= 100000)       return HIC "【曠世大俠】" NOR;
/*
                        else if (shen >= 10000)   return HIC "【 大  俠 】" NOR;
                        else if (shen >= 1000)    return HIC "【 俠  客 】" NOR;
                        else if (shen >= 100)     return HIC "【 少  俠 】" NOR;
*/
                        else if (shen <= -100000) return HIC "【 魔  王 】" NOR;
/*
                        else if (shen <= -10000)  return HIC "【 大  魔 】" NOR;
                        else if (shen <= -1000)   return HIC "【 魔  頭 】" NOR;
                        else if (shen <= -100)    return HIC "【 少  魔 】" NOR;
*/
                        else switch(ob->query("class")) {
                        case "bonze":
                             if (budd >= 150)     return HIY "【 長  老 】" NOR;
                             else if (budd >=120) return HIY "【 聖  僧 】" NOR;
                             else if (budd >= 90) return HIY "【 羅  漢 】" NOR;
                             else if (budd >= 60) return HIC "【 尊  者 】" NOR;
                             else if (budd >= 40) return HIC "【 禪  師 】" NOR;
                             else if (budd >= 30) return HIG "【 比  丘 】" NOR;
                             else if (age  <= 16) return "【 小和尚 】";
                             else                 return "【 僧  人 】";
                        case "taoist":            /*正一派*/
                        case "quanzhen":          /*全真派*/
                             if (ob->query_skill("taoism",1)>100)
                                                  return "【 真  人 】";
                             else if (age <= 16)  return "【 小道士 】";
                             else if (age <= 30)  return "【 道  士 】";
                             else                 return "【 道  長 】";
                        case "scholar":
                             if (age <= 16)       return "【 學  童 】";
                             else if (age <= 35)  return "【 書  生 】";
                             else if (age <= 50)  return "【 老秀才 】";
                             else                 return "【 儒  士 】";
                        case "bandit":            return "【 盜  賊 】";
                        case "legend":            return "【 遊  俠 】";
                        case "traveller" :        return "【 浪  子 】";
                        case "ninemoon":          return "【 惡  棍 】";
                        case "officer":           /* 官差 */
                             budd = (int)ob->query("officerlvl");
                             if (budd == 9)       return HIR"【 神  捕 】" NOR;
                             else if (budd == 8)  return YEL"【一等侍衛】" NOR;
                             else if (budd == 7)  return YEL"【二等侍衛】" NOR;
                             else if (budd == 6)  return YEL"【三等侍衛】" NOR;
                             else if (budd == 5)  return HIG"【 總捕頭 】" NOR;
                             else if (budd == 4)  return HIG"【副總捕頭】" NOR;
                             else if (budd == 3)  return HIG"【 捕  頭 】" NOR;
                             else if (budd == 2)  return HIG"【 捕  快 】" NOR;
                             else if (budd == 1)  return HIG"【實習捕快】" NOR;
                             else return "【 官  差 】";
                        case "fighter":           return "【 武  者 】";
                        case "swordsman":         return "【 劍  士 】";
                        case "alchemist":         return "【 方  士 】";
                        case "shaman":            return "【 巫  醫 】";
                        case "lama":              return "【 喇  嘛 】";
                        case "generals":          return "【 武  將 】";
                        case "guard":             return "【 衛  士 】";
                        case "minion":            return "【 家  臣 】";
                        case "prostitute":        return "【 龜  公 】";
                        case "beggar":
                             if (age <= 16)       return "【 小叫化 】";
                             else if (shen >1000) return "【 俠  丐 】";
                             else if (shen<-1000) return "【 惡  丐 】";
                             else                 return "【 叫化子 】";
                        case "eunach":
                             budd = ob->query_skill("bixie-jian",1);
                             if (budd >= 110)     return HIY "【大內高手】" NOR;
                             else if (budd >=100) return HIY "【東廠萬戶】" NOR;
                             else if (budd >= 90) return HIY "【東廠千戶】" NOR;
                             else if (budd >= 80) return HIY "【東廠百戶】" NOR;
                             else if (budd >= 70) return HIY "【東廠十戶】" NOR;
                             else if (budd >= 60) return HIY "【東廠公公】" NOR;
                             else                 return "【 內  侍 】";
                        default:
                             if (age <= 16)       return "【 少  年 】";
                             else                 return "【 平  民 】";
                        }
                }
        }
}

string query_respect(object ob)
{
        int age;
        string str;

        // 正常用不到，主要是處理questd初始化可能造成調用報錯
        if (!objectp(ob))
        {
                return "大俠";
        }

        if( stringp(str = ob->query("rank_info/respect")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                        case "lama":
                                if( age < 18 ) return "小師太";
                                else return "師太";
                                break;
                        case "taoist":            /*正一派*/
                        case "quanzhen":          /*全真派*/
                                if( age < 18 ) return "小仙姑";
                                else return "仙姑";
                                break;
                        default:
                                if( age < 18 ) return "小姑娘";
                                else if( age < 30 ) return "姑娘";
                                else if( age < 50 ) return "大嬸";
                                else return "婆婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                        case "lama":
                                if( age < 18 ) return "小師父";
                                else return "大師";
                                break;
                        case "taoist":            /*正一派*/
                        case "quanzhen":          /*全真派*/
                                if( age < 18 ) return "道兄";
                                else return "道長";
                                break;
                        case "scholar":
                                if( age < 18 ) return "小相公";
                                else if( age < 50 ) return "相公";
                                else return "老先生";
                                break;
                        case "fighter":
                        case "swordsman":
                                if( age < 18 ) return "小老弟";
                                else if( age < 50 ) return "壯士";
                                else return "老前輩";
                                break;
                        default:
                                if( age < 20 ) return "小兄弟";
                                else if( age < 50 ) return "壯士";
                                else return "老爺子";
                                break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                        case "lama":
                                if( age < 18 ) return "小賊尼";
                                if( age < 30 ) return "賊尼";
                                else return "老賊尼";
                                break;
                        case "taoist":            /*正一派*/
                        case "quanzhen":          /*全真派*/
                                if( age < 18 ) return "小妖女";
                                if( age < 30 ) return "妖女";
                                else return "老妖婆";
                                break;
                        default:
                                if( age < 18 ) return "小娘皮";
                                if( age < 25 ) return "小賤人";
                                if( age < 40 ) return "賊婆娘";
                                else return "死老太婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                        case "lama":
                                if( age < 18 ) return "小賊禿";
                                if( age < 50 ) return "死禿驢";
                                else return "老禿驢";
                                break;
                        case "taoist":            /*正一派*/
                        case "quanzhen":          /*全真派*/
                                if( age < 18 ) return "小雜毛";
                                if( age < 30 ) return "死牛鼻子";
                                else return "老雜毛";
                                break;
                        case "scholar":
                                if( age < 18 ) return "小書呆子";
                                else if( age < 50 ) return "臭書呆子";
                                else return "老童生";
                                break;
                        default:
                                if( age < 20 ) return "小王八蛋";
                                if( age < 30 ) return "直娘賊";
                                if( age < 50 ) return "臭賊";
                                if( age < 80 ) return "老匹夫";
                                else return "老不死";
                                break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                        case "lama":
                                if( age < 50 ) return "貧尼";
                                else return "老尼";
                                break;
                        case "taoist":            /*正一派*/
                        case "quanzhen":          /*全真派*/
                                return "貧道";
                                break;
                        default:
                                if( age < 20 ) return "小女子";
                                if( age > 50 ) return "老身";
                                else return "妾身";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                        case "lama":
                                if( age < 18 ) return "小衲";
                                if( age < 40 ) return "貧僧";
                                else return "老衲";
                                break;
                        case "taoist":            /*正一派*/
                        case "quanzhen":          /*全真派*/
                                if( age < 18 ) return "小道";
                                if( age < 30 ) return "貧道";
                                else return "老道";
                                break;
                        case "scholar":
                                if( age < 30 ) return "晚生";
                                else return "不才";
                                break;
                        default:
                                if( age < 50 ) return "在下";
                                else return "老頭子";
                                break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                        case "lama":
                                if( age < 50 ) return "貧尼";
                                else return "老尼";
                                break;
                        case "taoist":            /*正一派*/
                        case "quanzhen":          /*全真派*/
                                return "本仙姑";
                                break;
                        default:
                                if( age < 20 ) return "本姑娘";
                                if( age < 30 ) return "本姑奶奶";
                                else return "老孃";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                        case "lama":
                                if( age < 50 ) return "大和尚我";
                                else return "老和尚我";
                                break;
                        case "taoist":            /*正一派*/
                        case "quanzhen":          /*全真派*/
                                if( age < 30 ) return "本山人";
                                return "老道我";
                                break;
                        case "scholar":
                                if( age < 50 ) return "本相公";
                                else return "老夫子我";
                                break;
                        default:
                                if( age < 20 ) return "本少爺我";
                                if( age < 40 ) return "大爺我";
                                else return "老子";
                                break;
                        }
        }
}
string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (ob->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;
        default :
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
        }
}

string query_self_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (this_player()->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 >= a2)
                        return "愚兄我";
                else
                        return "小弟我";
        }
}
