#You are working with a large dataset of email addresses. Your task is to detect duplicate email addresses efficiently.
#Author - Vedika Udgir

emails = [
    "support.team@fakemail.com",
    "admin.accounts@fakemail.com",
    "marketing.promo@fakemail.com",
    "developer.beta@fakemail.com",
    "warehouse.shipping@fakemail.com",
    "client.onboard@fakemail.com",
    "marketing.promo@fakemail.com",
    "project.alpha@fakemail.com",
    "billing.invoices@fakemail.com",
    "admin.accounts@fakemail.com",
    "warehouse.shipping@fakemail.com",
    "marketing.promo@fakemail.com",
    "feedback.survey@fakemail.com",
    "admin.accounts@fakemail.com",
    "user.profile@fakemail.com"
]

uniqueEmails = [email for email in emails if emails.count(email) == 1]
print("Unique email addresses:", uniqueEmails)