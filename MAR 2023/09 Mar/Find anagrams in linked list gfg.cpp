class Solution
{
public:
  vector<Node *> findAnagrams(struct Node *head, string s)
  {
    vector<int> a(26, 0), b(26, 0);
    vector<Node *> ans;
    for (int i = 0; i < s.size(); i++)
      b[s[i] - 'a']++;
    int i = 0, j = 0;
    Node *f = head, *sl = head;
    while (f != NULL)
    {
      char p = f->data;
      a[p - 'a']++;
      if (j - i + 1 == s.size())
      {
        bool ok = true;
        for (int k = 0; k < 26; k++)
          if (a[k] != b[k])
            ok = false;
        if (ok == true)
        {
          Node *head1 = new Node(sl->data);
          Node *p = head1;
          sl = sl->next;
          while (sl != NULL and f != NULL and sl->next != NULL and sl != f)
          {
            Node *k = new Node(sl->data);
            p->next = k;
            p = k;
            sl = sl->next;
          }
          Node *k = new Node(sl->data);
          p->next = k;
          p = k;
          sl = sl->next;
          for (int l = 0; l < 26; l++)
            a[l] = 0;
          i = j + 1;
          ans.emplace_back(head1);
        }
        else
        {
          char d = sl->data;
          a[d - 'a']--;
          i++;
          sl = sl->next;
        }
      }
      j++;
      f = f->next;
    }
    return ans;
  }
};
