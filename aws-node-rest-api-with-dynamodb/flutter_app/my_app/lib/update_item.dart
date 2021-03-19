import 'package:http/http.dart' as http;

Future<void> updateName(String ID, String newName) async {
  var url =
      "https://6wfudnghd2.execute-api.us-east-1.amazonaws.com/dev/todos/$ID";
  return http
      .put(url, body: "{" + "\"name\": \"$newName\" }")
      .then((http.Response response) {
    final int statusCode = response.statusCode;
    print(response);
    print(statusCode);
    if (statusCode == 200) {
      print("Success");
      return;
    }else{
      throw new Exception("Error while fetching data");
    }
  });
}