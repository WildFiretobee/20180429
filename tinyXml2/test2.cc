 ///
 /// @file    test2.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-22 16:13:55
 ///

#include <iostream>
using std::cout;
using std::endl;

using System;
using System.Text.RegularExpressions;

namespace Kwanhong.Utilities
{
  /// <summary>
  /// HtmlToText ��ժҪ˵����
  /// </summary>
 public class HtmlToText
 {
 public string Convert(string source)
 {
 string result;

 //remove line breaks,tabs
 result = source.Replace("/r", " ");
 result = result.Replace("/n", " ");
 result = result.Replace("/t", " ");

 //remove the header
 result = Regex.Replace(result, "(<head>).*(</head>)", string.Empty, RegexOptions.IgnoreCase);

 result = Regex.Replace(result, @"<( )*script([^>])*>", "<script>", RegexOptions.IgnoreCase);
 result = Regex.Replace(result, @"(<script>).*(</script>)", string.Empty, RegexOptions.IgnoreCase);

 //remove all styles
 result = Regex.Replace(result, @"<( )*style([^>])*>", "<style>", RegexOptions.IgnoreCase); //clearing attributes
 result = Regex.Replace(result, "(<style>).*(</style>)", string.Empty, RegexOptions.IgnoreCase);

 //insert tabs in spaces of <td> tags
 result = Regex.Replace(result, @"<( )*td([^>])*>", " ", RegexOptions.IgnoreCase);

 //insert line breaks in places of <br> and <li> tags
 result = Regex.Replace(result, @"<( )*br( )*>", "/r", RegexOptions.IgnoreCase);
 result = Regex.Replace(result, @"<( )*li( )*>", "/r", RegexOptions.IgnoreCase);

 //insert line paragraphs in places of <tr> and <p> tags
 result = Regex.Replace(result, @"<( )*tr([^>])*>", "/r/r", RegexOptions.IgnoreCase);
 result = Regex.Replace(result, @"<( )*p([^>])*>", "/r/r", RegexOptions.IgnoreCase);

 //remove anything thats enclosed inside < >
 result = Regex.Replace(result, @"<[^>]*>", string.Empty, RegexOptions.IgnoreCase);

 //replace special characters:
 result = Regex.Replace(result, @"&amp;", "&", RegexOptions.IgnoreCase);
 result = Regex.Replace(result, @"&nbsp;", " ", RegexOptions.IgnoreCase);
 result = Regex.Replace(result, @"&lt;", "<", RegexOptions.IgnoreCase);
 result = Regex.Replace(result, @"&gt;", ">", RegexOptions.IgnoreCase);
 result = Regex.Replace(result, @"&(.{2,6});", string.Empty, RegexOptions.IgnoreCase);

 //remove extra line breaks and tabs
 result = Regex.Replace(result, @" ( )+", " ");
 result = Regex.Replace(result, "(/r)( )+(/r)", "/r/r");
 result = Regex.Replace(result, @"(/r/r)+", "/r/n");

 return result;
 }

 }//end class
}//end namespace