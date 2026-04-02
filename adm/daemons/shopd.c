// 商業系統總控程序

#include <ansi.h>
#include <config.h>
#include <getconfig.h>
public mapping *query_shop();                                  // 返回店鋪列表
public int is_inited();                                        // 返回店鋪是否全部初始化
private int check_owner(string arg);                           // 檢查店鋪主人和店鋪夥計主人是否相同
public int change_owner(object me,string arg,string owner);    // 修改店鋪店主（店鋪主人和店鋪夥計主人）
public int is_owner(string owner);                             // 查看玩家 owner 是否店鋪店主
public int close_all(object me);                               // 關閉所有店鋪
public int close_shop(object me,string arg);                   // 關閉指定店鋪
public int open_all(object me);                                // 開放所有店鋪
public int open_shop(object me,string arg);                    // 開放指定店鋪
public int reset_all(object me);                               // 初始化所有店鋪
public int reset_shop(object me,string arg);                   // 初始化指定店鋪
public int list_shop(object me);                               // 查詢店鋪
public string do_modify(object obj, object me, string arg);    // 修改店鋪夥計的屬性
public string do_stock(object ob, object me, string arg);      // 標價並出售貨物
public string do_unstock(object ob, object me, string arg);    // 取下貨物
public string do_list(object ob, object me, string arg);       // 查詢貨物
public int do_listall(object me);                              // 查所有商店貨物
public int do_buy(object obj, object me, string arg);          // 購買貨物
private int player_pay(object who, object target, int amount); // 付款，計算商業評價以及稅率
public string do_jiezhang(object ob, object me);               // 結帳（店鋪主人不在線時候的店鋪收入）
public string list_invite(object ob, object me);               // 查詢貴賓列表
public string do_invite(object ob, object me, string arg);     // 設置|取消 貴賓
public string list_ban(object ob, object me);                  // 查詢黑戶列表
public string do_ban(object ob, object me, string arg);        // 設置|取消 黑戶
public string list_order(object ob,object me);		       // 店主顯示預約
public string do_order(object ob,object me,string arg);	       // 預約物品
private void destruct_it(object ob);
public void reset_goods(object obj);                              // 檢查玩家擺攤物品
string makeup_space(string s,int max);
string *special_props = ({ "short", "long" });
string filter_color(string arg);
string top;							//最大銷售額店鋪名(例如清香園)
int color_len(string arg);

nosave mapping *all_shop = ({
        ([
                "id":             "北京",
                "name":           "瑞蚨祥",
                "start_room":     "beijing_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "長安",
                "name":           "同盛祥",
                "start_room":     "changan_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "成都",
                "name":           "清香園",
                "start_room":     "chengdu_shop",
                "type":           "shop",
                "price":          300,
        ]),
        ([
                "id":             "揚州",
                "name":           "月明軒",
                "start_room":     "yangzhou_shop",
                "type":           "shop",
                "price":          800,
        ]),
        ([
                "id":             "蘇州",
                "name":           "採芝齋",
                "start_room":     "suzhou_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "杭州",
                "name":           "頤香齋",
                "start_room":     "hangzhou_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "福州",
                "name":           "聚春園",
                "start_room":     "fuzhou_shop",
                "type":           "shop",
                "price":          300,
        ]),
        ([
                "id":             "無錫",
                "name":           "聚豐園",
                "start_room":     "wuxi_shop",
                "type":           "shop",
                "price":          300,
        ]),
        ([
                "id":             "開封",
                "name":           "福興齋",
                "start_room":     "kaifeng_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "延平",
                "name":           "雙溪樓",
                "start_room":     "yanping_shop",
                "type":           "shop",
                "price":          50000,
        ]),
        ([
                "id":             "泉州",
                "name":           "福人頤",
                "start_room":     "quanzhou_shop",
                "type":           "shop",
                "price":          50000,
        ]),
        ([
                "id":             "佛山",
                "name":           "天海樓",
                "start_room":     "foshan_shop",
                "type":           "shop",
                "price":          50000,
        ]),
/*
        ([
                "id":             "大理",
                "name":           "撥雲堂",
                "start_room":     "dali_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "武昌",
                "name":           "悅新昌",
                "start_room":     "wuchang_shop",
                "type":           "shop",
                "price":          300,
        ]),
        ([
                "id":             "靈州",
                "name":           "同福居",
                "start_room":     "lingzhou_shop",
                "type":           "shop",
                "price":          300,
        ]),
        ([
                "id":             "伊犁",
                "name":           "牛大碗",
                "start_room":     "yili_shop",
                "type":           "shop",
                "price":          300,
        ]),
*/
});
public mapping *query_shop()
{
        return all_shop;
}
public string query_top()
{
	return top;
}
public int is_inited()
{
        int i, is_ok;
        object shop;

        is_ok = 1;

        for (i = 0; i < sizeof(all_shop); i++)
        {
                shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

                if (shop->query("short")==query_top()) continue;
                if (! shop || shop->query("shop_type"))
                {
                        is_ok = 0;
                        break;
                }
		else
                {
                        if ((shop->query("vendor_goods") &&
                             sizeof(shop->query("vendor_goods")) > 0) ||
                             shop->query("all_vendor_goods") ||
                             shop->query("owner") != "VOID_SHOP")
                        {
                                is_ok = 0;
                                break;
                        }
                }
        }
        return is_ok;
}

private int check_owner(string arg)
{
        int i, have_it;
        object the_shop;
        string shop_owner;

        have_it = 0;
        for (i = 0; i < sizeof(all_shop); i++)
        {
                if (all_shop[i]["id"] == arg)
                {
                        have_it = 1;
                        break;
                }
        }

        // 沒有找到指定的店鋪
        if (! have_it)
                return 0;

        the_shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

        if (! the_shop)
                return 0;

        shop_owner = the_shop->query("owner");
        return 1;
}

public int change_owner(object me, string arg, string owner)
{
        int i, have_it;
        object the_shop;

        have_it = 0;
        for (i = 0; i < sizeof(all_shop); i++)
        {
                if (all_shop[i]["id"] == arg)
                {
                        have_it = 1;
                        break;
                }
        }

        if (! have_it)
        {
                tell_object(me, "對不起，" + arg + "店鋪並不存在。\n");
                return 1;
        }

        if (! check_owner(arg))
        {
                tell_object(me, "警告：" + arg + "店鋪主人和店鋪夥計主人數據異常，請仔細檢查。\n");

                log_file("static/shop", sprintf("%s店鋪數據異常，時間：%s。\n", arg, ctime(time())));
                return 1;
        }

        the_shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

        if (the_shop)
        {
                the_shop->set("owner", owner);
                the_shop->save();
                tell_object(me, arg + "店鋪店主修改完畢。\n");
        } else
        {
                tell_object(me, arg + "店鋪文件不存在，請仔細查看。\n");
                return 1;
        }

        return 1;
}

public int is_owner(string owner)
{
        int i;
        object shop;

        for (i = 0; i < sizeof(all_shop); i ++)
        {
                shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

                if (! objectp(shop))
                        return 0;

                if (shop->query("owner") == owner)
                        return 1;
        }
        return 0;
}

public int close_all(object me)
{
        int i;

        for (i = 0; i < sizeof(all_shop); i++)
        {
                close_shop(me, all_shop[i]["id"]);
        }

        return 1;
}

// 關閉店鋪是修改店鋪的 shop_type 爲 0
public int close_shop(object me, string arg)
{
        int i, have_it;
        object the_shop;

        have_it = 0;

        for (i = 0; i < sizeof(all_shop); i++)
        {
                if (all_shop[i]["id"] == arg)
                {
                        have_it = 1;
                        break;
                }
        }

        if (! have_it)
        {
                tell_object(me, "對不起，" + arg + "店鋪並不存在。\n");
                return 1;
        }

        if (! check_owner(arg))
        {
                tell_object(me, "警告：" + arg + "店鋪主人和店鋪夥計主人數據異常，請仔細檢查。\n");
                log_file("static/shop",sprintf("%s店鋪數據異常，時間：%s。\n", arg, ctime(time())));
                return 1;
        }

        the_shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

        if (the_shop)
        {
                the_shop->set("shop_type", 0);
                the_shop->save();
                tell_object(me, arg + "店鋪成功關閉。\n");
        } else
        {
                tell_object(me, arg + "店鋪文件不存在，請仔細查看。\n");
                return 1;
        }
        return 1;
}

public int open_all(object me)
{
        int i;
        for (i = 0; i < sizeof(all_shop); i++)
                open_shop(me, all_shop[i]["id"]);
        return 1;
}

// 開放店鋪是修改店鋪的 shop_type 爲 1
public int open_shop(object me, string arg)
{
        int i, have_it;
        object the_shop;

        have_it = 0;
        for (i = 0; i < sizeof(all_shop); i++)
        {
                if (all_shop[i]["id"] == arg)
                {
                        have_it = 1;
                        break;
                }
        }
        if (! have_it)
        {
                tell_object(me, "對不起，" + arg + "店鋪並不存在。\n");
                return 1;
        }

        if (! check_owner(arg))
        {
                tell_object(me, "警告：" + arg + "店鋪主人和店鋪夥計主人數據異常，請仔細檢查！\n");
                log_file("static/shop", sprintf("%s店鋪數據異常，時間：%s。\n", arg, ctime(time())));
                return 1;
        }

        the_shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

        if (the_shop)
        {
                the_shop->set("shop_type", 1);
                the_shop->save();
                tell_object(me, arg + "店鋪成功開放！\n");
        }
	else
        {
                tell_object(me, arg + "店鋪文件不存在，請仔細查看！\n");
                return 1;
        }
        return 1;
}

public int reset_all(object me)
{
        int i;
        int topscore;
        object the_shop;

        topscore = 0;
        for (i=0; i<sizeof(all_shop);i++)
        {
	        the_shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);
	        if ( the_shop->query("score") > topscore )
	        {
	        	topscore = the_shop->query("score");
	        	top = the_shop->query("short");
	        }
        }
        for (i = 0; i < sizeof(all_shop); i++)
        {
        	if (topscore > 0 && all_shop[i]["name"]==query_top()) continue;
                reset_shop(me, all_shop[i]["id"]);
        }
        return 1;
}

// 初始化店鋪包括：
// 關閉店鋪
// 設置店鋪和夥計的主人爲空值
// 清除夥計的貨物以及夥計的存款
// 清除夥計的貴賓和黑戶
public int reset_shop(object me, string arg)
{
        int i, have_it;
        string *props, prop;
        object the_shop, the_waiter;
        mapping m;

        have_it = 0;
        for (i = 0; i < sizeof(all_shop); i++)
        {
                if (all_shop[i]["id"] == arg)
                {
                        have_it = 1;
                        break;
                }
        }
        if (! have_it)
        {
                tell_object(me,"對不起，" + arg + "店鋪並不存在。\n");
                return 1;
        }

        the_shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);
//from here
	tell_object(me,arg+"店鋪初始化aa成功！\n");
	return 1;
// to here
        if (the_shop)
        {
                the_shop->set("shop_type", 0);
                the_shop->set("owner", "VOID_SHOP");
                the_shop->set("balance", 0);
                the_shop->delete("vendor_goods");
                the_shop->delete("vendor_goods_num");
                the_shop->delete("all_vendor_goods");
                the_shop->delete("invite");
                the_shop->delete("ban");
                the_shop->delete("waiter");
                the_shop->delete("score");

                the_shop->save();

                tell_object(me, arg + "店鋪成功初始化！\n");
        } else
        {
                tell_object(me, arg + "店鋪文件不存在，請仔細查看！\n");
                return 1;
        }

        the_waiter = present("huo ji", the_shop);
        if (the_waiter)
        {
                if (arrayp(m = the_shop->query("waiter")) &&
			sizeof(props = keys(m)))
                {
/* 替代foreach */
			for (i = 0; i < sizeof(props); i++)
			{
				if(prop == props[i])
				{
	                                if (prop == "name")
						the_waiter->set_name("店鋪夥計", ({ "huo ji", "huo", "ji" }));
					if (prop == "long")
						the_waiter->set("long","他就是這家店鋪的夥計。\n");
					the_waiter->delete(prop);
				}
			}
/*
                        foreach (prop in props)
                        {
                                if (prop == "name")
                                        the_waiter->set_name("店鋪夥計", ({ "huo ji", "huo", "ji" }));
                                if (prop == "long")
                                        the_waiter->set("long","他就是這家店鋪的夥計。\n");
                                the_waiter->delete(prop);
                        }
*/
                        the_shop->delete("waiter");
                }
                tell_object(me, arg + "夥計成功初始化！\n");
        } else
        {
                tell_object(me, arg + "店鋪夥計不存在，請仔細查看！\n");
                return 1;
        }
        return 1;
}

public int list_shop(object me)
{
        int i;
        string arg, na, msg;
        object ob, the_shop;
        string str;

        msg = WHT "當前" + LOCAL_MUD_NAME() + "的店鋪列表如下：\n" NOR;
        msg += HIC"≡" HIY "------------------------------------------------------------------------" HIC "≡\n" NOR;
        for (i = 0; i < sizeof(all_shop); i++)
        {
                arg = all_shop[i]["id"];

                if (! check_owner(arg))
                        continue;

                the_shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

                if (! the_shop)
                        continue;

                if (objectp(ob = find_player(the_shop->query("owner"))) &&
			this_player()->visible(ob))
                        na = HIR + ob->query("name");
                else
                {
                        na = GRN "離線玩家";
                }

               msg += sprintf(WHT " 店鋪：" HIG "%s[" HIW "%s" HIG "] " NOR ,
               			all_shop[i]["name"], arg);

               str = (the_shop->query("shop_type") &&
                               the_shop->query("owner") != "VOID_SHOP") ?
                               HIG " 營業中 " NOR : HIY "暫不營業" NOR,
               msg += sprintf(HIG"%8s%s"NOR,str,makeup_space(str,8));

               msg += WHT " 銷售積分：" HIC ;
               if ((int)the_shop->query("score")<=0)
               str = HIY"暫無"NOR;
               else
               str = sprintf("%d",the_shop->query("score"));
	       msg += sprintf("%-6s%s",str,makeup_space(str,6));

               str = the_shop->query("owner") == "VOID_SHOP" ?
                               HIC "風兒(系統)" NOR : na +
                               "(" + the_shop->query("owner") + ")" NOR,
               msg += sprintf(WHT "  店鋪主人：" HIG "%-20s%s" NOR ,str,makeup_space(str,20));

               msg += "\n";
        }
        msg += HIC"≡"HIY"------------------------------------------------------------------------" HIC "≡\n" NOR;
        msg += WHT"總共有" + chinese_number(sizeof(all_shop)) + "家店鋪。\n"NOR;
        tell_object(me, msg);
        return 1;
}

public string do_modify(object obj, object me, string arg)
{
        string item, msg;
        mapping dbase;
        object room;

        room = environment(obj);

        if (! room->query("shop_type"))
                return "對不起，該店鋪目前已經被巫師關閉。\n";

        if (! arg || sscanf(arg,"%s %s", item, msg) != 2)
                return "設定格式爲：modify <項目> <內容>\n";

        if (CHINESE_D->check_control(msg))
                return "描述不可有控制符。\n";

        if (CHINESE_D->check_space(msg))
                return "描述必需不含空格。\n";

        if (CHINESE_D->check_return(msg))
                return "描述必需不含回車鍵。\n";

        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "$S$", BLINK);

        switch(item)
        {
        case "desc":
                if (CHINESE_D->check_length(msg) > 100)
                        return "你所設定的描述太長了。\n";

                obj->set("long", msg + NOR "\n");
                room->set("waiter/long", msg + NOR "\n");

                room->save();
                return WHT "你爲店鋪夥計設定好了描述。\n" NOR;

        case "nickname" :
                if (CHINESE_D->check_length(msg) > 20)
                        return "你所設定的描述太長了。\n";

                obj->set("nickname", msg + NOR);
                room->set("waiter/nickname", msg + NOR);

                room->save();
                return WHT "你爲店鋪夥計設定好了綽號。\n" NOR;

        case "title" :
                if (CHINESE_D->check_length(msg) > 20)
                        return "你所設定的描述太長了。\n";

                obj->set("title", msg + NOR);
                room->set("waiter/title", msg + NOR);

                room->save();
                return WHT "你爲店鋪夥計設定好了頭銜。\n" NOR;

        case "name" :
                if (CHINESE_D->check_length(msg) > 10)
                        return "你所設定的描述太長了。\n";

                if (! is_chinese(msg))
                        return "店鋪夥計的姓名只能用中文。\n";

                dbase = obj->query_entire_dbase();
                dbase["name"] = msg;

                room->set("waiter/name", msg);

                room->save();
                return WHT "你爲店鋪夥計設定好了名字。\n" NOR;
        }
        return "你要修改什麼？\n";
}

public string do_stock(object ob, object me, string arg)
{
        object  goods, obj2;
        int value;
        mapping all_goods, all_goods_num;
        object room;

        room = environment(ob);

        if (! room->query("shop_type"))
                return "對不起，該店鋪目前已經被巫師關閉。\n";

        if (! arg || ! sscanf(arg, "%s value %d", arg, value) == 2)
                return "指令格式：stock <貨物> value * ( 其中 * 是以銅板作單位的價格 )\n";

        if (! value)
                return "指令格式：stock <貨物> value * ( 其中 * 是以銅板作單位的價格 )\n";

        if (value > 10000000 && !wizardp(me))
                return "店鋪最多標價一千兩黃金，你就別那麼心黑了吧。\n";
        if (! (goods = present(arg, me)) || ! objectp(goods))
                return "你身上並沒有這個貨物啊！\n";
        if (goods->query("no_sell"))
                return "這個東西太招搖了，還是別拿出來販賣。\n";
        if (goods->query("no_sell"))
                return "這個東西太招搖了，還是別拿出來販賣。\n";
	if (goods->query("no_get") || goods->query("no_drop") ||
		goods->query("no_put") || goods->query("no_beg") ||
		goods->query("no_steal") || goods->query("no_drop") ||
		goods->query("ownmake") || goods->query("owner"))
                return "這個東西擺不上貨架，就暫時別拿出來賣啦。\n";
  if (goods->query("last_value")) return "這種便宜貨，就別拿出來賣啦。\n";
	if (goods->query("wiz_only") && !wizardp(me))
		return "這個東西只能在巫師商店裏賣。\n";
        if (goods->is_character())
                return "你不能販賣活物。\n";
        if (goods->query("money_id"))
                return "你把錢也拿來出售？\n";
        if (room->query("all_vendor_goods") >= 80)
                return "你店鋪上的東西太多了，先收幾種貨物再擺吧。\n";

        all_goods = room->query("vendor_goods");

        if (! all_goods)
                all_goods = ([ ]);

        all_goods_num = room->query("vendor_goods_num");
        if (! all_goods_num) all_goods_num = ([ ]);
//	if (all_goods_num[base_name(goods)] > 14 )
//		return "同樣的物品不能擺放超過十五件。\n";
     if (goods->is_unique() && all_goods_num[base_name(goods)]>=2)
        return "這種東西太寶貴了，店裏放太多了會招賊的。\n";
        all_goods[base_name(goods)] = value;
        all_goods_num[base_name(goods)] += 1;

        room->set("vendor_goods", all_goods);
        room->set("vendor_goods_num", all_goods_num);
        room->add("all_vendor_goods", 1);

        message_vision(HIW "$N" HIW "將『" HIG + goods->name(1) + HIW "』標上" HIY + MONEY_D->price_str(value) + HIW "的價格開始出售。\n" NOR, me);
        room->save();
        if (goods->query_amount() && goods->query_amount() > 1)
        {
                goods->set_amount((int)goods->query_amount() - 1);
                obj2 = new(base_name(goods));
                obj2->set_amount(1);
                destruct(obj2);
        }
        else destruct(goods);
        return "你擺置好了貨物。\n";
}

public string do_unstock(object ob, object me, string arg)
{
        object  goods, room;
        int i;
        mapping all_goods, all_goods_num;
        string *goods_key, ob_file;

        seteuid(getuid());
        room = environment(ob);
        if (! room->query("shop_type"))
                return "對不起，該店鋪目前已經被巫師關閉。\n";

        if (! arg)
                return "指令格式：unstock <貨物>\n";

        if (! room->query("all_vendor_goods"))
                return "你現在還沒有擺上任何貨物。\n";

        all_goods = room->query("vendor_goods");
        all_goods_num = room->query("vendor_goods_num");

//        if (sizeof(all_inventory(me)) >= MAX_ITEM_CARRIED)
        if (sizeof(all_inventory(me)) >= 15 && !wizardp(me))
                return "你身上的東西太多了，沒法從貨架上取東西。\n";

        all_goods = room->query("vendor_goods");

        if (! all_goods)
                all_goods = ([ ]);

        all_goods_num = room->query("vendor_goods_num");

        if (! all_goods_num)
                all_goods_num = ([ ]);

        goods_key = keys(all_goods);

        if (arrayp(goods_key))
        {
                for (i = 0; i < sizeof(goods_key); i++)
                {
                        if (goods_key[i]->id(arg))
                                ob_file = goods_key[i];
                        else

                        if (filter_color(goods_key[i]->name(1)) == arg)
                                ob_file = goods_key[i];
                }
        }

        if (! ob_file)
                return "現在"+ environment(ob)->query("short") + "的貨架上並沒有這樣貨物。\n";

        goods = new(ob_file);
        goods->set_amount(1);

        room->add("all_vendor_goods", -1);
        all_goods_num[base_name(goods)] -= 1;

        if (all_goods_num[base_name(goods)] == 0)
        {
                map_delete(all_goods, base_name(goods));
                map_delete(all_goods_num, base_name(goods));
        }

        message_vision(HIW "$N" HIW "將『" HIG + goods->name(1) + HIW"』從貨架上取下來不賣了。\n" NOR, me);

        room->set("vendor_goods", all_goods);
        room->set("vendor_goods_num", all_goods_num);
        room->save();

        if (! goods->move(me))
        {
                goods->move(environment(me));
                tell_object(me, "可是你已經拿不動了，只好把" + goods->name(1) + NOR "放在地上。\n");
        }
        return "你取好了貨物。\n";
}

public string do_list(object ob, object me, string arg)
{
        mapping goods, goods_num;
        string *gks;
        object  room;
        string msg;
        int i;

        mapping price;
        mapping unit;
        mapping count;
        string  short_name;
        string  prefix;
        string  *dk;

        room = environment(ob);
        if (! room->query("shop_type"))
                return "對不起，該店鋪目前已經被巫師關閉。\n";

        if (room->query("ban") &&
		member_array(me->query("id"), room->query("ban")) != -1)
                return "你是這家店鋪不受歡迎的人物，無法購買東西。\n";

        if (! room->query("all_vendor_goods"))
		return "現在"+room->query("short")+"目前並沒有出售任何貨物。\n";

        goods = room->query("vendor_goods");

        if (! goods)
                goods = ([]);

        goods_num = room->query("vendor_goods_num");

        if (! goods_num)
                goods_num = ([]);

        count   = ([]);
        unit    = ([]);
        price   = ([]);

        gks = keys(goods);
        for (i = 0; i < sizeof(gks); i++)
        {
                object gob;
                call_other(gks[i], "???");

                if (! objectp(find_object(gks[i])))
                {
                        log_file("user_vendor", sprintf("No found vendor good:%s\n", gks[i]));
                        continue;
                }

                gob = find_object(gks[i]);
                short_name = gob->name(1) + "(" + gob->query("id") + ")";

                if (gob->query("base_unit"))
                        prefix = "base_";
                else
                        prefix = "";

                unit  += ([ short_name : gob->query(prefix + "unit") ]);
                price += ([ short_name : goods[gks[i]] ]);
                count += ([ short_name : goods_num[gks[i]] ]);
        }

        msg = "該店鋪目前出售以下物品：\n";
        msg += "-------------------------------------------------------\n";
        dk = sort_array(keys(unit), 1);

        for (i = 0; i < sizeof(dk); i++)
        {
                int p;
                p = price[dk[i]];
		msg += sprintf("%" + sprintf("%d", (30 + color_len(dk[i])) ) + "-s：每%s%s" CYN "(現貨%s)\n" NOR, dk[i], unit[dk[i]], MONEY_D->price_str(p), chinese_number(count[dk[i]]) + unit[dk[i]]);
        }

        msg += "-------------------------------------------------------\n";

        if (me->query("id") == room->query("owner"))
                msg += "總共" + chinese_number(room->query("all_vendor_goods")) + "件貨物。\n";

        if (room->query("invite/" + me->query("id")))
                msg += WHT"您是本店貴賓，購買所有貨物均享受"HIW+chinese_number(room->query("invite/"+me->query("id")))+HIW"折"NOR+WHT"的優惠。\n" NOR;
        return msg;
}

public int do_buy(object obj, object me, string arg)
{
        mapping goods,goods_num;
        
        int value;
        string ob_file, *goods_key;
        object ob;
        
        int i;
        object room;

        room = environment(obj);
        if (! room->query("shop_type"))
        {
               tell_object(me, "對不起，該店鋪目前已經被巫師關閉。\n");
               return 1;
        }

        if (room->query("ban") &&
		member_array(me->query("id"), room->query("ban")) != -1)
        {

               tell_object(me, "你是這家店鋪不受歡迎的人物，無法購買東西。\n");
               return 1;
        }

        if(me->is_busy())
        {
                tell_object(me, "什麼事都得等你忙完再說吧！\n");
                return 1;
        }

        if (! arg)
        {
                tell_object(me, "你要買什麼東西？\n");
                return 1;
        }

        if (sizeof(all_inventory(me)) >= MAX_ITEM_CARRIED)
        {
                tell_object(me, "你身上的東西太多了，先處理一下再買東西吧。\n");
                return 1;
        }

        goods = room->query("vendor_goods");

        if (! goods) goods = ([ ]);

        goods_num = room->query("vendor_goods_num");

        if (!goods_num) goods_num = ([]);

        goods_key = keys(goods);

        if (arrayp(goods_key))
        {
                for (i = 0; i < sizeof(goods_key); i++)
                {
                        if (goods_key[i]->id(arg)) ob_file = goods_key[i];
                        else
	                        if (filter_color(goods_key[i]->name(1)) == arg)
	                                ob_file = goods_key[i];
                }
        }

        if (! ob_file)
        {
                tell_object(me, "該店鋪並沒有出售這樣貨物。\n");
                return 1;
        }

        value = goods[ob_file];

        // 如果是貴賓，則有優惠
        if (room->query("invite/" + me->query("id")))
                value = value * room->query("invite/" + me->query("id")) / 10;

        ob = new(ob_file);
        call_out("destruct_it", 0, ob);

        switch (player_pay(me, obj, value))
        {
        case 0:
                tell_object(me, CYN + obj->name(1) + NOR + CYN "冷笑道：窮光蛋，一邊待著去。\n" NOR);
                return 1;

        case 2:
                tell_object(me, CYN + obj->name(1) + NOR + CYN "皺眉道：您還有沒有零錢啊？銀票我可找不開。\n" NOR);
                return 1;

        default:
                if (ob->query_amount())
                {
                        message_vision("$N從$n那裏買下了" + ob->short() + "。\n", me, obj);
                }
		else
                {
                        message_vision("$N從$n那裏買下了一" + ob->query("unit") + ob->query("name") + "。\n", me, obj);
                }
//             log_file("shop_log",sprintf("%-20s在%6s花%9s買下",who->query("name")+"("+who->query("id")+")",environment(who)->query("short"),amount));

              log_file("shop_log",ob->query("name")+"。\n");
                ob->move(me, 1);
                goods_num[ob_file] -= 1;

                if (goods_num[ob_file] == 0)
                {
                        map_delete(goods, ob_file);
                        map_delete(goods_num, ob_file);
                }

                room->set("vendor_goods", goods);
                room->set("vendor_goods_num", goods_num);
                room->add("all_vendor_goods", -1);
        }
        me->start_busy(1);
        room->save();
        return 1;
}

private int player_pay(object who, object target, int amount)
{
        object t_ob, g_ob, s_ob, c_ob, owner;
        int tc, gc, sc, cc, left;
        int v;
        int pay_amount;

        seteuid(getuid());

        if (amount >= 100000 && t_ob = present("cash_money", who))
                tc = t_ob->query_amount();
        else
        {
                tc = 0;
                t_ob = 0;
        }

        if (g_ob = present("gold_money", who))
                gc = g_ob->query_amount();
        else
                gc = 0;

        if (s_ob = present("silver_money", who))
                sc = s_ob->query_amount();
        else
                sc = 0;

        if (c_ob = present("coin_money", who))
                cc = c_ob->query_amount();
        else
                cc = 0;

        v = cc + sc * 100 + gc * 10000;

        if (amount < 100000 && v < amount)
        {
                if (present("cash_money", who))
                        return 2;
                else
                        return 0;
        }

        v += tc * 100000;

        if (v < amount)
                return 0;
        else {
                left = v - amount;
                if (tc)
                {
                        tc = left / 100000;
                        left %= 100000;
                }
                gc = left / 10000;
                left = left % 10000;
                sc = left / 100;
                cc = left % 100;

                if (t_ob && ! g_ob && gc)
                {
                        g_ob = new(GOLD_OB);
                        g_ob->move(who, 1);
                }

                if (t_ob)
                        t_ob->set_amount(tc);

                if (g_ob)
                        g_ob->set_amount(gc);
                else
                        sc += (gc * 100);

                if (s_ob)
                {
                        s_ob->set_amount(sc);
                } else
                if (sc)
                {
                        s_ob = new(SILVER_OB);
                        s_ob->set_amount(sc);
                        s_ob->move(who, 1);
                }

                if (c_ob)
                {
                        c_ob->set_amount(cc);
                } else
                if (cc)
                {
                        c_ob = new(COIN_OB);
                        c_ob->set_amount(cc);
                        c_ob->move(who, 1);
                }

                pay_amount = amount * 99 / 100;

                if (owner = find_player(environment(target)->query("owner")))
                {
                        owner->add("balance", pay_amount);
                        owner->add("trade_balance", pay_amount);

                        if (query_ip_number(owner) != query_ip_number(who))
                                owner->add("vendor_score", pay_amount / 10000);
	                environment(target)->add("score",pay_amount/10000);
                } else
                        environment(target)->add("balance", pay_amount);
                log_file("shop_log",sprintf("%-20s在 %6s 花%9i買下",who->query("name")+"("+who->query("id")+")",environment(who)->query("short"),amount));
                return 1;
        }
}

public string do_jiezhang(object ob, object me)
{
       int amount;
       object room;

       room = environment(ob);
       if (! room->query("shop_type"))
               return "對不起，該店鋪目前已經被巫師關閉。\n";

       amount = room->query("balance");

       if (amount < 1) return "您不在的時候還沒有任何的收入。\n";

       me->add("balance", amount);
       me->add("trade_balance", amount);
       me->add("vendor_score", amount / 10000);

       tell_object(me, HIY"您不在線時共有"+MONEY_D->price_str(amount)+HIY"的收入，現已全部轉入您的銀號。\n"NOR);
       room->set("balance", 0);
       room->save();
       return "結帳完畢，請即時覈對數目。\n";
}

public string list_invite(object ob, object me)
{
        int i;
        string msg, *invite_key;
        mapping invite;
        object room;

        room = environment(ob);
        if (! room->query("shop_type"))
                return "對不起，該店鋪目前已經被巫師關閉。\n";

        invite = room->query("invite");

        if (! invite || sizeof(invite) < 1)
                return "您並沒有設定任何的貴賓。\n";

        msg = HIC "您所定義的貴賓有以下幾位：\n" NOR;
        msg += HIC "≡" HIY "------------------------" HIC "≡\n" NOR;
        invite_key = sort_array(keys(invite), 1);

        for (i = 0; i < sizeof(invite_key); i++)
        {
                msg += sprintf(CYN "%-20s  " WHT "%s折\n" NOR,
                               invite_key[i], chinese_number(invite[invite_key[i]]));
        }

        msg += HIC "≡" HIY "------------------------" HIC "≡\n" NOR;
        msg += HIC "總共有 " HIY + sizeof(invite) + HIC " 個貴賓。\n" NOR;
        return msg;
}

public string do_invite(object ob, object me, string arg)
{
        int num;
        object  room;

        room = environment(ob);

        if (! room->query("shop_type"))
                return "對不起，該店鋪目前已經被巫師關閉。\n";

        if (! sscanf(arg, "%s %d", arg, num) == 2)
                return "指令格式：invite <id> <折數>\n";

        if (num < 1 || num > 10)
                return "指令格式：invite <id> <折數>\n";

        if (num == 10)
        {
                if (! room->query("invite/" + arg))
                        return CYN + ob->name(1) + NOR + CYN "對你說道：老闆，那 " + arg + " 本來就不是我們店的貴賓啊。\n" NOR;

                room->delete("invite/" + arg);
                room->save();
                return CYN + ob->name(1) + NOR + CYN "翻開帳簿用劃了劃，奸笑道：老闆，已經按照你的吩咐取消掉 " + arg + " 的貴賓資格了。\n" NOR;
        }

        if (sizeof(room->query("invite")) >= 30)
                return "您已經設定了三十個貴賓，把不常來的先劃掉吧。\n";

        room->set("invite/" + arg, num);
        room->save();

        return CYN + ob->name(1) + NOR + CYN "翻開帳簿邊寫邊說道：老闆，已經按照你的吩咐對 " WHT + arg + CYN " 實行" + HIY + chinese_number(num) + "折" + NOR + CYN "優惠。\n" NOR;
}

public string list_ban(object ob, object me)
{
        int i;
        string msg, *ban;
        object room;

        room = environment(ob);

        if (! room->query("shop_type"))
               return "對不起，該店鋪目前已經被巫師關閉。\n";

        ban = room->query("ban");

        if (! ban || sizeof(ban) < 1)
        {
                msg = "您並沒有設定任何的黑戶。\n";
                return msg;
        }
        msg = HIC "您所定義的黑戶有如下玩家：\n" NOR;
        msg += HIC "≡" HIY "------------------------" HIC "≡\n" NOR;
        for (i = 0;i < sizeof(ban);i++)
        {
                msg += sprintf(CYN "  %s\n" NOR, ban[i]);
        }
        msg += HIC "≡" HIY "------------------------" HIC "≡\n" NOR;
        msg += HIC "總共有 " HIY + sizeof(ban) + HIC " 個黑戶。\n" NOR;
        return msg;
}

public string do_ban(object ob, object me, string arg)
{
        string the_id, type, *ban;
        object room;

        room = environment(ob);

        if (! room->query("shop_type"))
               return "對不起，該店鋪目前已經被巫師關閉。\n";

        ban = room->query("ban");

        if (! ban)
                ban = ({ });

        if (sscanf(arg, "%s %s", type, the_id) == 2 && type == "-")
        {
                if (member_array(the_id, ban) == -1)
                        return CYN + ob->name(1) + NOR + CYN "對你說道：老闆，那 " + arg + " 本來就不是我們店的黑戶啊。\n" NOR;

                ban -= ({ the_id });
                room->set("ban", ban);
                room->save();
                return CYN + ob->name(1) + NOR + CYN "翻開帳簿劃了劃，對你賠笑道：老闆，已經取消了 " + the_id + " 黑戶身份。\n" NOR;
        }

        if (member_array(arg, ban) != -1)
                return CYN + ob->name(1) + NOR + CYN "奸笑着道：老闆，您忘記了？那" + arg + "早已被列爲黑戶啦。\n" NOR;

        if (sizeof(ob->query("ban")) >= 30)
                return "您已經設定了三十個黑戶，還是先劃掉一些吧。\n";

        ban += ({ arg });
        room->set("ban", ban);
        room->save();
        return CYN + ob->name(1) + NOR + CYN "翻開帳簿邊寫邊說道：老闆，已經按照你的吩咐將 " WHT + arg + CYN " 列爲了黑戶。\n"NOR;
}
public string do_order(object ob,object me,string arg)
{
	object room;
 
	string ab;
	string buyer,obname;
	string *clist;

	room = environment(ob);

        if (! room->query("shop_type"))
               return "對不起，該店鋪目前已經被巫師關閉。\n";

        if (me->query("id")==room->query("owner"))
        {
        	//店主操作
        	if (sscanf(arg,"%s %s",ab,buyer)!=2)
        		return "刪除訂單內容命令： order - 顧客id [某一商品]\n";

        	if (ab!="-")
        		return "刪除訂單內容命令： order - 顧客id [某一商品]\n";


        	if (sscanf(buyer,"%s %s",buyer,obname)==2)
        	{
       			if (!arrayp(room->query("order/"+buyer)))
	       		return "顧客"+buyer+"並沒有定購過商品。\n";
        		clist = room->query("order/"+buyer);
        		if (member_array(obname,clist)==-1)
        			return "顧客"+buyer+"並沒有定購過"+HIC+obname+NOR+"這樣商品。\n";
        		clist -= ({ obname });
        		if (sizeof(clist)>0)
        		room->set("order/"+buyer,clist);
        		else room->delete("order/"+buyer);
        		room->save();
        		return "清除顧客"+buyer+"定購"+HIC+obname+NOR+"的消息。\n";
        	}
        	else
        	{
       			if (!arrayp(room->query("order/"+buyer)))
	       		return "顧客"+buyer+"並沒有定購過商品。\n";
        		room->delete("order/"+buyer);
        		room->save();
        		return "清除顧客"+buyer+"的所有定購消息。\n";
        	}
        }
	else
	{
		buyer = me->query("id");
		clist = room->query("order/"+buyer);
		if (sscanf(arg,"- %s",arg)==1)
		{
			if (!arrayp(clist) || member_array(arg,clist)==-1)
			return "你並沒有定購這樣商品。\n";
			clist -= ({arg});
        		if (sizeof(clist)>0)
        		room->set("order/"+buyer,clist);
        		else room->delete("order/"+buyer);
        		room->save();
        		return "清除定購"+HIC+arg+NOR+"的消息。\n";
		}
		if (arrayp(clist))
		{
			if (member_array(arg,clist)>=0)
			return "你已經定購過了"+arg+"。\n";
			if (sizeof(clist)>20)
			return "你在這個店鋪定購的東西已經很多了，等店主先處理完吧。\n";
		}
		else clist = ({});
		clist += ({ arg });
		room->set("order/"+buyer,clist);
		room->save();
		tell_object(find_player(room->query("owner")),"店裏有新的定購消息了，快去處理吧。\n");
		return "你在"+room->query("short")+"定購商品"+arg+"成功，請等待店主處理。\n";
	}
}
public string list_order(object ob,object me)
{
	mapping orders;
	int i;
	string str;
	string *korder;
	object room;
	string *clist;

        room = environment(ob);
        if (! room->query("shop_type"))
               return "對不起，該店鋪目前已經被巫師關閉。\n";

        if (me->query("id")!=room->query("owner") && !wizardp(me))
        {
	        clist = room->query("order/"+me->query("id"));
	        if (!arrayp(clist) || sizeof(clist)<1)
        	return "你想定購什麼？order 商品名稱\n";
        	str = HIW"你已經在"+room->query("short")+"定購了以下物品：\n"NOR;
        	str += implode(clist,"\n");
        	str += "\n";
        	return str;
        }

	if (!mapp(orders = room->query("order")) || sizeof(orders)<1)
		return "目前沒有任何定購消息。\n";

	str = HIG"當前店鋪定購消息如下：\n"NOR;
	korder = keys(orders);
	for (i=0;i<sizeof(orders);i++)
	{
		if (arrayp(orders[korder[i]]))
		{
			str += HIW"玩家"+korder[i]+"要求購買：\n"NOR;
			str += implode(orders[korder[i]],"\n");
			str += "\n";
		}
	}
	str += HIC"處理顧客定購消息請用 order - 顧客id [商品名稱]\n"NOR;
	return str;
}

private void destruct_it(object ob)
{
        if (! ob || environment(ob))
                return;

        destruct(ob);
}
public int do_listall(object me)
{
        int i, j;
        object shop, room;
        mapping goods, goods_num, price, unit, count;
        string the_shop, na, msg, short_name, prefix, *dk, *gks;

        msg = HIY "貨物總表\n" NOR;
	tell_object(me, msg);
        for (j = 0; j < sizeof(all_shop); j++)
        {
                the_shop = all_shop[j]["id"];
                if (! check_owner(the_shop)) continue;
                room = load_object(SHOP_DIR + all_shop[j]["start_room"]);
                if (! room) continue;

                if (objectp(shop = find_player(room->query("owner"))))
                        na = HIR + shop->query("name");
                else
                {
                        na = GRN "離線玩家";
                }

		msg = HIC "≡"HIY"--------------------------------------------------------------------------" HIC "≡\n" NOR;
                msg += sprintf(HIG "%s[" HIW "%s" HIG "] (%s"HIG")" NOR,
                               all_shop[j]["name"],
                               the_shop,
                               room->query("owner") == "VOID_SHOP" ?
                               HIC "系統" NOR : na +
                               "(" + room->query("owner") + ")" NOR,);

		if (! room->query("all_vendor_goods"))
		{
			msg += HIR"無貨。\n"NOR;
			tell_object(me, msg);
			continue;
		}
		else msg += "\n";
		msg += HIC"≡"HIY"--------------------------------------------------------------------------" HIC "≡\n" NOR;

		goods = room->query("vendor_goods");
		if (! goods) goods = ([]);
		goods_num = room->query("vendor_goods_num");
		if (! goods_num) goods_num = ([]);

		count = ([]);
		unit  = ([]);
		price = ([]);

		gks = keys(goods);
		for (i = 0; i < sizeof(gks); i++)
		{
			object gob;
			call_other(gks[i], "???");

			if (! objectp(find_object(gks[i])))
			{
				log_file("user_vendor", sprintf("No found vendor good:%s\n", gks[i]));
	                        continue;
			}

			gob = find_object(gks[i]);
			short_name = gob->name(1)+"("+gob->query("id")+")";

			if (gob->query("base_unit")) prefix = "base_";
			else prefix = "";

			unit  += ([ short_name : gob->query(prefix + "unit") ]);
			price += ([ short_name : goods[gks[i]] ]);
			count += ([ short_name : goods_num[gks[i]] ]);
		}

		dk = sort_array(keys(unit), 1);

		for (i = 0; i < sizeof(dk); i++)
		{
			msg += sprintf("%" + sprintf("%d", (30 + color_len(dk[i])) ) + "-s：每%s%s" CYN "(現貨%s)\n" NOR, dk[i], unit[dk[i]], MONEY_D->price_str(price[dk[i]]), chinese_number(count[dk[i]]) + unit[dk[i]]);
//			msg += sprintf("%s-%d" CYN "(%d)\n" NOR, dk[i], price[dk[i]], count[dk[i]]);
		}
		tell_object(me, msg);
        }
        return 1;
}

string filter_color(string arg)
{
	if(!arg) return "";
	arg = replace_string(arg, BLK, "");
	arg = replace_string(arg, RED, "");
	arg = replace_string(arg, GRN, "");
	arg = replace_string(arg, YEL, "");
	arg = replace_string(arg, BLU, "");
	arg = replace_string(arg, MAG, "");
	arg = replace_string(arg, CYN, "");
	arg = replace_string(arg, WHT, "");
	arg = replace_string(arg, HIR, "");
	arg = replace_string(arg, HIG, "");
	arg = replace_string(arg, HIY, "");
	arg = replace_string(arg, HIB, "");
	arg = replace_string(arg, HIM, "");
	arg = replace_string(arg, HIC, "");
	arg = replace_string(arg, HIW, "");
	arg = replace_string(arg, NOR, "");
	arg = replace_string(arg, BBLK, "");
	arg = replace_string(arg, BRED, "");
	arg = replace_string(arg, BGRN, "");
	arg = replace_string(arg, BYEL, "");
	arg = replace_string(arg, BBLU, "");
	arg = replace_string(arg, BMAG, "");
	arg = replace_string(arg, BCYN, "");
	arg = replace_string(arg, HBRED, "");
	arg = replace_string(arg, HBGRN, "");
	arg = replace_string(arg, HBYEL, "");
	arg = replace_string(arg, HBBLU, "");
	arg = replace_string(arg, HBMAG, "");
	arg = replace_string(arg, HBCYN, "");
	arg = replace_string(arg, HBWHT, "");
	arg = replace_string(arg, NOR, "");

	return arg;
}
int color_len(string str)
{
	int i;
	int extra;

	extra = 0;
	for (i = 0; i < strwidth(str); i++)
	{
		if (str[i] == ESC[0])
		{
			while((extra++, str[i] != 'm') && i < strwidth(str))
				i++;
		}
	}
	return extra;
}

public void reset_goods(object obj)
{
	mapping goods;
	string *gks;
	object ob;
	int i;

  if (! obj ) return;
	goods = obj->query("vendor_goods");
  if (! goods ) return;
	gks = keys(goods);
	for (i = 0; i < sizeof(gks); i++)
	{
		if (!objectp(ob = find_object(gks[i]))  ||
		    !objectp(environment(ob)) ||
		     environment(ob) != obj )
		map_delete(goods, gks[i]);
	}
	obj->set("vendor_goods", goods);
}
string makeup_space(string s,int max)
{
	string *ansi_char = ({
		BLK,   RED,   GRN,   YEL,   BLU,   MAG,   CYN,   WHT,
		BBLK,  BRED,  BGRN,  BYEL,  BBLU,  BMAG,  BCYN,
		       HIR,   HIG,   HIY,   HIB,   HIM,   HIC,   HIW,
		       HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
		NOR
	});

	string space = s;
	int i, space_count;

	for (i = 0; i < sizeof(ansi_char); i ++)
		space = replace_string(space, ansi_char[i], "", 0);

	space_count = sizeof(s) - sizeof(space);
	if (sizeof(s) >= max)
		space_count = max - sizeof(space);

	space = "";

	for (i = 0; i < space_count; i ++) space += " ";
	return space;
}