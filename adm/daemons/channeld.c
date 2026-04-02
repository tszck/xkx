
inherit F_DBASE;

#include <ansi.h>
#include <net/dns.h>
#include <net/macros.h>
#define NEW_PERIOD 32400



mapping blocks = ([
  "all" : 0,
  "rumor" : 0,
  "chat"  : 0,
  "xkx" : 0,
  "sing"  : 0,
  "family": 0,
  "party" : 0,
]);
mapping channels = ([
  "sys":  ([
      "msg_speak" : HIR "【系統】%s：%s\n" NOR,
      "msg_emote" : HIR"【系統】%s\n" NOR,
      "wiz_only"  : 1,
    ]),
  "wiz":  ([
      "msg_speak" : YEL "【巫師】%s：%s\n" NOR,
      "msg_emote" : YEL "【巫師】%s\n" NOR,
      "wiz_only"  : 1,
    ]),
  "gwiz": ([
      "msg_speak" : HIY "【網際巫師】%s：%s\n" NOR,
      "msg_emote" : HIY "【網際巫師】%s\n" NOR,
      "wiz_only"  : 1,
      "intermud": GWIZ,
      "channel": "gwiz",
      "filter"    : 1,
      "intermud_emote": 1,
    ]),
  "debug":([
      "msg_speak" : HIW "【調試】%s：%s\n" NOR,
      "msg_emote" : HIW "【調試】%s\n" NOR,
      "wiz_only"  : 1,
    ]),
  "snp":  ([
      "msg_speak" : HIB "【監聽】%s：%s\n" NOR,
      "msg_emote" : HIB "【監聽】%s\n" NOR,
      "wiz_only"  : 1,
    ]),
// qst tune for display quest message
  "qst":  ([
      "msg_speak" : HIR "【任務】%s：%s\n" NOR,
      "msg_emote" : HIR "【任務】%s\n" NOR,
      "wiz_only"  : 1,
    ]),
  "xkx":  ([
      "msg_speak" : HIY "【俠客行】%s：%s\n" NOR,
      "msg_emote" : HIY "【俠客行】%s\n" NOR,
      "intermud"  : GCHANNEL,
      "channel": "xkx",
      "filter"    : (: $1["MUDLIB"]=="Xia Ke Xing" :),
      "all_target": 1,
      "age_limit" : 1,
      "intermud_emote": 1,
    ]),
// keep the channel name as "es" to be compatible with other ES2 type muds.
// es tune for all the mud without filter limit
  "es": ([
      "msg_speak" : CYN "【網際閒聊】%s：%s\n" NOR,
      "msg_emote" : CYN "【網際閒聊】%s\n" NOR,
      "intermud"  : GCHANNEL,
      "channel": "es",
      "filter"    : 1,
      "age_limit" : 1,
      "intermud_emote": 1,
    ]),
  "party":([
      "msg_speak" : GRN "【幫會】%s：%s\n" NOR,
      "msg_emote" : GRN "【幫會】%s\n" NOR,
      "party_only": 1,
    ]),
  "family":([
      "msg_speak" : YEL "【門派】%s：%s\n" NOR,
      "msg_emote" : YEL "【門派】%s\n" NOR,
      "family_only": 1,
    ]),
  "chat": ([
      "msg_speak" : HIC "【閒聊】%s：%s\n" NOR,
      "msg_emote" : HIC "【閒聊】%s\n" NOR,
    ]),
  "snow": ([
      "msg_speak" : HIY "【風聞】%s：%s\n" NOR,
      "msg_emote" : HIY "【風聞】%s\n" NOR,
      "system_only" : 1,
    ]),
  "rumor":([
      "msg_speak" : HIM "【謠言】%s：%s\n" NOR,
      "msg_emote" : HIM "【謠言】%s\n" NOR,
      "anonymous" : "某人",
      "age_limit" : 1,
    ]),
  "sing": ([
      "msg_speak" : HIG "【歌唱】%s唱道：%s......\n" NOR,
      "msg_emote" : HIG "【歌唱】%s\n" NOR,
    ]),
]);

// 增加函數set_block和query_block，用來設置和判斷所有玩家的公共頻道情況。 Added by Spacenet@FXLT
int set_block(string ch_name, int val)
{
  return (blocks[ch_name] = val);
}

int query_block(string ch_name)
{
  return (blocks[ch_name]);
}

void create()
{
  seteuid(getuid());
// This is required to pass intermud access check.
  set("channel_id", "頻道精靈");
}

varargs int do_channel(object me, string verb, string arg, int cemote)
{
  object *ob;
  string *tuned_ch, who, arg1, party, family;
  int len, pointer;
  int emote;
  if (cemote) emote=cemote;

// Check if this is a channel emote.
  if(sizeof(verb)>0)
    if( verb[sizeof(verb)-1] == '*' )
    {
      emote = 1;
      verb = verb[0..<2];
    }
  if( !mapp(channels) || undefinedp(channels[verb]) ) return 0;

// 系統專用頻道
  if( channels[verb]["system_only"] &&
    userp(me) && !wizardp(me) )
    return 0;

// 門派頻道
  if( channels[verb]["family_only"] &&
    !me->query("family/family_name") )
    return notify_fail("你還是先加入一個門派再説吧。\n");
  if( channels[verb]["family_only"] )
  {
    family = me->query("family/family_name");
    channels[verb]["msg_speak"] = YEL"【"+family+YEL"】%s：%s\n"NOR;
    channels[verb]["msg_emote"] = YEL"【"+family+YEL"】%s\n"NOR;
  }

// 幫會頻道
  if( channels[verb]["party_only"] &&
    !me->query("party/party_name") )
    return notify_fail("你還是先加入一個幫會再説吧。\n");
  if( channels[verb]["party_only"] )
  {
    party = me->query("party/party_name");
    channels[verb]["msg_speak"] = GRN"【"+party+GRN"】%s：%s\n"NOR;
    channels[verb]["msg_emote"] = GRN "【"+party+GRN"】%s\n" NOR;
  }

  if( userp(me) )
  {
    if( channels[verb]["wiz_only"] && !wizardp(me) ) return 0;
// 增加對所有人的公共頻道是否被巫師關閉的判斷。
    if( query_block(verb) || (query_block("all") &&
      (verb == "rumor" || verb == "chat" ||
      verb == "sing" || verb == "xkx" ||
      verb == "family" || verb == "party" ||
      verb == "es" || verb == "snow"
      )))
      return notify_fail("這個公共頻道已經被巫師關閉了！\n");
// 如果在短時間內重複使用公共頻道，則封閉該玩家所有頻道3分鐘。
    if(me->query("channel/chat_block") &&
      (time()-me->query("channel/chat_block"))<0 )
      return notify_fail("你的交談頻道被暫時關閉了，請稍後再試。\n");
    if (me->query("chblk_on"))
      return notify_fail("你所有的頻道都被關閉了！\n");
    if (me->query("chblk_rumor") && (verb == "rumor"))
      return notify_fail("你的謠言頻道被關閉了！\n");
    if (me->query("chblk_chat") && (verb == "chat"))
      return notify_fail("你的聊天頻道被關閉了！\n");
    if (me->query("chblk_sing") && (verb == "sing"))
      return notify_fail("你的音樂頻道被關閉了！\n");
    if (me->query("chblk_xkx") && (verb == "xkx"))
      return notify_fail("你的俠客行頻道被關閉了！\n");
    if (me->query("chblk_family") && (verb == "family"))
      return notify_fail("你的門派頻道被關閉了！\n");
    if (me->query("chblk_party") && (verb == "party"))
      return notify_fail("你的幫會頻道被關閉了！\n");
    me->add("channel/chat_count",1);

    if (me->query("channel/chat_count")>2)
    {
      me->set("channel/chat_count",0);
      if(time()==me->query("channel/last_chat")&&!wizardp(me))
      {
        me->set("channel/chat_block",time()+180);
        message("system",HIR"【警告】"HIY"演若達多大吼一聲: “ｗａｋａｏ, Ｉ服了ｙｏｕ! 這麼能叫喚, 你先歇會兒吧。”, 説着拿了塊烤鴨屁股把"+me->query("name") +"的嘴塞了個嚴嚴實實。\n"NOR, users() );
        me->set("channel/last_chat",time());
        return notify_fail("因為實在太羅嗦，你的交談頻道被暫時關閉了。\n");
      }
      me->set("channel/last_chat",time());
    }
    if( !wizardp(me) &&
      (arg==(string)me->query_temp("last_channel_msg0") ||
      arg==(string)me->query_temp("last_channel_msg1") ||
      arg==(string)me->query_temp("last_channel_msg2") ||
      arg==(string)me->query_temp("last_channel_msg3") ||
      arg==(string)me->query_temp("last_channel_msg4")) )
      return notify_fail("用交談頻道説話請不要重複相同的訊息。\n");
    if( channels[verb]["age_limit"] && wiz_level(me) < 1 )
    {
      if( me->query("mud_age") < NEW_PERIOD )
        return notify_fail("你剛剛立足江湖，説話還沒那麼響亮。\n");
    }

// If we speaks something in this channel, then must tune it in.
    tuned_ch = me->query("channels");
    if( !pointerp(tuned_ch) ) me->set("channels", ({ verb }) );
    else
      if( member_array(verb, tuned_ch)==-1 )
        me->set("channels", tuned_ch + ({ verb }) );
  }

// Support of channel emote
// 如果是emote  那麼把emote分析出來 做成args繼續下一步
//  if( emote && !channels[verb]["intermud_emote"])
    if( emote && !cemote )
  {
    string vb, emote_arg;
    if( nullp(arg) ) return 0;
    if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 )
    {
      vb = arg;
      emote_arg = "";
    }
    if( channels[verb]["anonymous"] )
      arg = EMOTE_D->do_emote(me, vb, emote_arg, 1,1);
    else
    {
      arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 0, !undefinedp(channels[verb]["intermud"]));
// varargs mixed do_emote(object me, string verb, string arg, int channel_emote, int rumor_emote, int intermud)
     if(!arg)
      {
        string id, site;
        if(sscanf(emote_arg,"%s@%s",id,site)==2)
        {
          "/adm/daemons/network/services/gemote_q"->send_msg(channels[verb]["channel"],me,vb,id,site,channels[verb]["filter"]);
//送出了哪些東西？           頻道,發送者,動作名,對方id,對方地址,過濾條件
          return 1;
        }
      }
    }
    if( !arg ) return 0;
  }
//emote now ok //
//  tf(sprintf("after emote:\n是否是emote?\t%s\narg=%s\n ",emote,arg));
// Make the identity of speaker.
//   是誰説的話
  if( channels[verb]["anonymous"] )
  {
    who = channels[verb]["anonymous"];
    if (userp(me))
      do_channel( this_object(), "sys", sprintf("謠言：%s(%s)。", me->name(),me->query("id")));
  }
  else
   who = me->query("channel_id");

  if( !stringp(who) && objectp(me) )
    {
      who = me->query("name");
			if (me->query_temp("pretend") && arrayp(me->query_temp("apply/pid")))
			who=me->name()+"[" + capitalize(me->query_temp("apply/pid")[0]) + "]";
      else if(me->query("id"))
      who=who+"[" + capitalize(me->query("id")) + "]";
    }
   if (!stringp(who))
     do_channel(this_object(),"sys","err when get names who use channel\n");
// Ok, now send the message to those people listening us.
// 説給誰聽
  ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
//  返回users()經過this_object()->filter_listener(channels[verb])過濾後的結果
  if( !arg ) arg = "我好寂寞啊，誰來陪我聊天？";

  len=strlen(arg);
  while(len>1 && arg[len-1]=='\n')
    arg=arg[0..((len--)-2)];
//remove excessive return at the end. by mon 9/20/97

  if(userp(me))
  {
//可以允許玩家自由編輯對話的顏色。
    arg=replace_string(arg, "$BLK$", "[30m");
    arg=replace_string(arg, "$RED$", "[31m");
    arg=replace_string(arg, "$GRN$", "[32m");
    arg=replace_string(arg, "$YEL$", "[33m");
    arg=replace_string(arg, "$BLU$", "[34m");
    arg=replace_string(arg, "$MAG$", "[35m");
    arg=replace_string(arg, "$CYN$", "[36m");
    arg=replace_string(arg, "$WHT$", "[37m");
    arg=replace_string(arg, "$HIR$", "[1;31m");
    arg=replace_string(arg, "$HIG$", "[1;32m");
    arg=replace_string(arg, "$HIY$", "[1;33m");
    arg=replace_string(arg, "$HIB$", "[1;34m");
    arg=replace_string(arg, "$HIM$", "[1;35m");
    arg=replace_string(arg, "$HIW$", "[1;37m");
    arg=replace_string(arg, "$HIC$", "[1;36m");
    arg=replace_string(arg, "$HBRED$", "[41;1m");
    arg=replace_string(arg, "$HBGRN$", "[42;1m");
    arg=replace_string(arg, "$HBYEL$", "[43;1m");
    arg=replace_string(arg, "$HBBLU$", "[44;1m");
    arg=replace_string(arg, "$HBMAG$", "[45;1m");
    arg=replace_string(arg, "$HBCYN$", "[46;1m");
    arg=replace_string(arg, "$HBWHT$", "[47;1m");
    arg=replace_string(arg, "$BLINK$", "[5m");
    arg=replace_string(arg, "$NOR$", "[m");
    arg +="[m";
    arg1=replace_string(arg, "$N", me->name());
  }
  else arg1=arg;
// 這裏是關鍵之一
  if( emote )
  {
// Support of old behavier of intermud emote.
//    if( channels[verb]["intermud_emote"] ) arg1 = who + " " + arg;
    message( "channel:" + verb, sprintf( channels[verb]["msg_emote"], arg1 ), ob );
  }
  else
    message( "channel:" + verb, sprintf( channels[verb]["msg_speak"], who, arg1 ), ob );
///// end////
// 這段幹嘛的？//
  if( arrayp(channels[verb]["extra_listener"]) )
  {
    channels[verb]["extra_listener"] -= ({ 0 });
    if( sizeof(channels[verb]["extra_listener"]) )
      channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
  }
////////////
  if( !undefinedp(channels[verb]["intermud"]) &&
    base_name(me) != channels[verb]["intermud"] )
  {
    if(userp(me))
    {
//      arg=replace_string(arg, "$N", me->name() + "[" + capitalize(me->query("id")) + "@" + Mud_name() + "]", 1);
      if (me->query_temp("pretend") && arrayp(me->query_temp("apply/pid")))
      	arg=replace_string(arg, "$N", me->name() + "[" + capitalize(me->query_temp("apply/pid")[0]) + "@" + Mud_name() + "]", 1);
      else
      	arg=replace_string(arg, "$N", me->name() + "[" + capitalize(me->parse_command_id_list()[0]) + "@" + Mud_name() + "]", 1);
//      arg=replace_string(arg, "$N", me->name());
    }
  ///網際傳輸就看這句話
    channels[verb]["intermud"]->send_msg( channels[verb]["channel"], me->query("id"), me->name(1), arg, emote, channels[verb]["filter"] );
//void send_msg(string channel, string id, string name, string msg, int emoted,   mixed filter)
//                我用的頻道,我的id,我的name,我傳的內容,是否emote,過濾
  }

  if( userp(me) )
  {
    if( !pointer = me->query_temp("chat_pointer") ) pointer = 0;
    pointer %= 5;
    me->set_temp("last_channel_msg" + (string)pointer, arg);
    me->set_temp("chat_pointer", pointer + 1);
  }

  return 1;
}

int filter_listener(object ppl, mapping ch)
{
// Don't bother those in the login limbo.
  if( !environment(ppl) ) return 0;

  if (ch["wiz_only"] ) return wizardp(ppl);
  if (ch["party_only"]) return wizardp(ppl) || this_player()->query("party/party_name") == ppl->query("party/party_name");
  if (ch["family_only"]) return wizardp(ppl) || this_player()->query("family/family_name") == ppl->query("family/family_name");

  return 1;
}

void register_relay_channel(string channel)
{
  object ob;

  ob = previous_object();
  if( undefinedp(channels[channel]) || !ob) return;
  if( arrayp(channels[channel]["extra_listener"]) )
  {
    if( member_array(ob, channels[channel]["extra_listener"]) >=0 )
      return;
    channels[channel]["extra_listener"] += ({ ob });
  }
  else channels[channel]["extra_listener"] = ({ ob });
}
